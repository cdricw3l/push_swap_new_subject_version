/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:01:59 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/21 09:14:30 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int push(t_data *data, int src, int dst)
{
    if (!data)
        return (NO_MOVE);
    if(src == STACK_A && dst == STACK_B)
    {
        data->b = data->a;
        data->size_b++;
        data->a++;
        data->size_a--;
    }
    if (src == STACK_B && dst == STACK_A)
    {
        data->a = data->b;
        data->size_a++;
        data->b--;
        data->size_b--;
    }
}