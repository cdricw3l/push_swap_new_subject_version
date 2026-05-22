/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:32:29 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/22 10:57:28 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_swap(int *p1, int *p2)
{
    int tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

float compute_disorder(t_data *data)
{
    int i;
    int j;
    float mistakes;
    float total_pairs;

    i = 0;
    mistakes = 0;
    total_pairs = 0;
    while (i < data->size_a)
    {
        j = i + 1;
        while (j < data->size_a)
        {
            total_pairs++;
            if (data->stack[i] > data->stack[j])
                mistakes++;
            j++;
        }
        i++;
    }
    return (mistakes / total_pairs);
}