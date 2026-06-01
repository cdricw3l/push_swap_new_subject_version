/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_immediat_inf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:42:36 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 18:42:53 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*immediat_inferior(t_global_data *data, int stack, int *value)
{
	int	*arr;
	int	*p1;
	int	i;

	p1 = &i;
	i = INT_MIN;
	// if (bigest_value(data, stack) == value)
	// 	return (value);
	if (stack == STACK_A)
	{
		arr = data->a;
		while (arr <= data->end)
		{
			if (*arr > *p1 && *arr < *value)
				p1 = arr;
			arr++;
		}
	}
	else if (stack == STACK_B)
	{
		arr = data->b;
		while (arr >= data->start)
		{
			if (*arr > *p1 && *arr < *value)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}
