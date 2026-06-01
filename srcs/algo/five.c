/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:32:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 10:56:15 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	five_values(t_global_data *data, int stack)
{
	if (!data || (stack != STACK_A && stack != STACK_B))
		return (ERR);
	if(ft_is_sort(data, stack))
		return (NO_MOVE);
	if(stack == STACK_A)
	{
		at_beginning(data, stack, smalest_value(data, STACK_A));
		push(data, stack, STACK_B, DISPLAY);
		at_beginning(data, stack, smalest_value(data, STACK_A));
		push(data, stack, STACK_B, DISPLAY);
		three_values(data, stack);
		push(data, STACK_B, stack, DISPLAY);
		push(data, STACK_B, stack, DISPLAY);

	}
	else if (stack == STACK_B)
	{
		at_beginning(data, stack, bigest_value(data, STACK_B));
		push(data, stack, STACK_A, DISPLAY);
		at_beginning(data, stack, bigest_value(data, STACK_B));
		push(data, stack, STACK_A, DISPLAY);
		three_values(data, stack);
		push(data, STACK_A, STACK_B, DISPLAY);
		push(data, STACK_A, STACK_B, DISPLAY);
	}
	return (OK);
}
