/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrugge <mabrugge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:09:52 by mabrugge          #+#    #+#             */
/*   Updated: 2026/06/01 17:54:43 by mabrugge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int associate_target(t_list *lst, t_global_data *data)
{
    t_list      *current;
    t_best_cost *cur;
    t_list      *tmp;
    t_target_result  target;

    current = lst;
    while (current)
    {
        cur = current->content;
        tmp = lst;
        if (cur->stack != STACK_B)
        {
            current = current->next;
            continue;
        }
        target = find_closet_value(cur, tmp);
        associate_one_target(cur, target, data);
        current = current->next;
    }
    return (OK);
}

int    associate_one_target(t_best_cost *cur, t_target_result  target, t_global_data *data)
{
    int         *min;
    
    if (target.found)
    {
        cur->target_value = target.best_cost;
        cur->address_ptr_target_value = target.ptr_to_value_a;
    }
    else
    {
        min = smalest_value(data, STACK_A);
        cur->target_value = *min;
        cur->address_ptr_target_value = min;
    }
    return (OK);
}

t_target_result find_closet_value(t_best_cost *cur, t_list *list)
{
    t_list      *tmp;
    t_target_result  target;
    t_best_cost *t;
    
    target.found = false;
    target.best_cost = 0;
    target.ptr_to_value_a = NULL;
    tmp = list;
    while (tmp)
    {
        t = tmp->content;
        if (t->stack == STACK_A && t->value > cur->value)
        {
            if (!target.found || t->value < target.best_cost)
            {
                target.best_cost = t->value;
                target.ptr_to_value_a = t->address_ptr_value;
                target.found = true;
            }
        }
        tmp = tmp->next;
    }
    return (target);
}

static int get_total_cost(t_best_cost *target, t_list *list)
{
    t_list      *current;
    t_best_cost *cur;

    current = list;
    while(current)
    {
        cur = current->content;
        if(cur->value == target->target_value)
            return (cur->number_of_move + target->number_of_move);
        current = current->next;
    }
   return (0);
}

t_best_cost *find_best_value(t_list *list)
{
    t_list      *current;
    t_best_cost *cur;
    t_best_cost *best;
    int         total;

    current = list;
    best = NULL;

    while (current)
    {
        cur = current->content;

        if (cur->stack == STACK_B)
        {
            total = get_total_cost(cur, list);
            if (!best || total < best->best_move)
            {
                best = cur;
                best->best_move = total;
            }
        }
        current = current->next;
    }
    return (best);
}

#include <assert.h>

int turkish(t_global_data *data)
{
    t_list          *list;
    t_best_cost     *best;
    while(data->size_a > 3)
    {
        push(data, STACK_A, STACK_B, DISPLAY);
    }
    three_values(data, STACK_A);
    list = NULL;
    while (data->size_b > 0)
    {
        free_list(&list);
        list = NULL;
        get_target_number(data, STACK_A, &list);
        get_target_number(data, STACK_B, &list);
        associate_target(list, data);
        best = find_best_value(list);
        if (!best)
            return (ERR);
        at_beginning(data, STACK_B, best->address_ptr_value);
        at_beginning(data, STACK_A, best->address_ptr_target_value);
        push(data, STACK_B, STACK_A, DISPLAY);
    }
    at_beginning(data, STACK_A, smalest_value(data, STACK_A));
    display_stack(data, STACK_A);
    display_stack(data, STACK_B);
    return (OK);
}
