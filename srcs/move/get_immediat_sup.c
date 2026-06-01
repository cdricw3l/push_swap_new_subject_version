/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_immediat_sup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:41:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 18:42:08 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*immediat_superior(t_global_data *data, int stack, int *value)
{
	int	*arr;
	int	*p1;
	int	i;

	i = INT_MAX;
	p1 = &i;
	// if (bigest_value(data, stack) == value)
	// 	return (value);
	if (stack == STACK_A)
	{
		if (!data->a)
			return (NULL);
		arr = data->a;
		while (arr <= data->end)
		{
			if (*arr < *p1 && *arr > *value)
				p1 = arr;
			arr++;
		}
	}
	else if (stack == STACK_B)
	{
		if (!data->b)
			return (NULL);
		arr = data->b;
		while (arr >= data->start)
		{
			if (*arr < *p1 && *arr > *value)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}
