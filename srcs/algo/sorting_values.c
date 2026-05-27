/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrugge <mabrugge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 09:44:49 by mabrugge          #+#    #+#             */
/*   Updated: 2026/05/27 09:47:03 by mabrugge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int selection_sort(t_global_data *data)
{
    display_stack(data, STACK_A);
    while(data->size_a > 3)
    {
        min_at_beginning(data, STACK_A);
        push(data, STACK_A, STACK_B, NO_DISPLAY);
    }
    display_stack(data, STACK_A);
    tree_values(data, STACK_A);
    display_stack(data, STACK_A);
    display_stack(data, STACK_B);
    while(data->b)
        push(data, STACK_B, STACK_A, DISPLAY);
    display_stack(data, STACK_A);
    return (OK);
}
