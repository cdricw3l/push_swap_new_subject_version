/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smalest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:40:29 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 18:40:50 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*smalest_value(t_global_data *data, int stack)
{
	int	*arr;
	int	*p1;
	int	i;

	i = INT_MAX;
	p1 = &i;
	if (stack == STACK_A)
	{
		arr = data->a;
		while (arr <= data->end)
		{
			if (*arr < *p1)
				p1 = arr;
			arr++;
		}
	}
	else if (stack == STACK_B)
	{
		arr = data->b;
		while (arr >= data->start)
		{
			if (*arr < *p1)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}