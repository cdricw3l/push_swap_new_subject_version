/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrugge <mabrugge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:09:52 by mabrugge          #+#    #+#             */
/*   Updated: 2026/05/31 18:17:05 by mabrugge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


// void display_cost_list(void *ptr)
// {

//     t_best_cost *cost;

//     printf("Value: %d\n", cost->value);
//     printf("Nombre de mouvement: %d\n", cost->number_of_move);
//     if(cost->move == rev_rotate)
//         printf("mouvement: rev_rotate\n");
//     else if(cost->move == rotate)
//         printf("mouvement: rotate\n");
//     if(cost->stack == STACK_A)
//         printf("stack: A\n");
//     else if (cost->stack == STACK_B)
//         printf("stack: B\n");
//     NL;
// }
int associate_target(t_list *lst, t_global_data *data)
{
    t_list      *current;
    t_list      *tmp;
    t_best_cost *cur;
    t_best_cost *t;
    int         best_value;
    int         *ptr_to_value_a;
    int         *min;
    bool         found;

    current = lst;
    while (current)
    {
        cur = current->content;
        if (cur->stack != STACK_B)
        {
            current = current->next;
            continue;
        }

        found = false;
        best_value = 0;
        ptr_to_value_a = NULL;

        tmp = lst;
        while (tmp)
        {
            t = tmp->content;
            if (t->stack == STACK_A && t->value > cur->value)
            {
                if (!found || t->value < best_value)
                {
                    best_value = t->value;
                    ptr_to_value_a = t->address_ptr_value;
                    found = true;
                }
            }
            tmp = tmp->next;
        }
        if (found)
        {
            cur->target_value = best_value;
            cur->address_ptr_target_value = ptr_to_value_a;
        }
        else
        {
            min = smalest_value(data, STACK_A);
            if (min)
            {
                cur->target_value = *min;
                cur->address_ptr_target_value = min;
            }
        }
//         printf(
//     "node=%d target=%d ptr=%p\n",
//     cur->value,
//     cur->target_value,
//     (void *)cur->address_ptr_target_value
// );
        current = current->next;
    }
    return (OK);
}

int search_best_value(t_list *lst)
{
    t_list          *current;
    t_list          *tmp;

    t_best_cost     *cur;
    t_best_cost     *t;

    current = lst;
    while(current)
    {
        cur = current->content;
        tmp = lst;
        while(tmp)
        {
            t = tmp->content;
            if(cur->stack == 1)
            {
                if (cur->target_value == t->value)
                    cur->best_move = cur->number_of_move + t->number_of_move;
            }
             tmp = tmp->next;
        }
        current = current->next;
    }
    return (OK);
}

// int *find_best_value(t_list *list, int stack)
// {
//     t_list          *current;
//     t_best_cost    *cur;
//     int            min_value;
//     int            *value_begin;

//     value_begin = NULL;
//     min_value = INT_MAX;
//     current = list;
//     //ft_lstremove_if(&current, STACK_A);
//     while(current)
//     {
//         cur = current->content;
//             if(cur->best_move < min_value && cur->stack == 1)
//             {
//                 min_value = cur->best_move;
//                 if(stack == STACK_A)
//                     value_begin = cur->address_ptr_value;
//                 else if(stack == STACK_B)
//                 {
//                     value_begin = cur->address_ptr_target_value; // a corriger
//                     cur->stack = 0;
//                 }   
//             }
//         current = current->next;
//     }
//     return (value_begin);
// }

t_best_cost *find_best_value(t_list *list)
{
    t_list          *current;
    t_best_cost     *cur;
    t_best_cost     *best;

    best = NULL;
    current = list;
    while (current)
    {
        cur = current->content;
        if (cur->stack == 1 && cur->processed == 0)
        {
            if (!best || cur->best_move < best->best_move)
                best = cur;
        }
        current = current->next;
    }
    if(best)
        best->processed = 1;
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
    while (data->b)
    {
        free_list(&list);
        list = NULL;
        get_target_number(data, STACK_A, &list);
        get_target_number(data, STACK_B, &list);
        associate_target(list, data);
        search_best_value(list);
        if(data->size_b > 1)
        {
            best = find_best_value(list);
            if (!best)
                return (ERR);
            at_beginning(data, STACK_B, best->address_ptr_value);
            at_beginning(data, STACK_A, best->address_ptr_target_value);
        }
        push(data, STACK_B, STACK_A, DISPLAY);
    }
    assert(data->size_b == 0);
    at_beginning(data, STACK_A, smalest_value(data, STACK_A));
    return (OK);
}
