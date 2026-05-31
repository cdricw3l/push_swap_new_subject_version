/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_beginning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:27:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/31 23:22:04 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static long	ft_abs(long value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

/**
 * @brief return if the movement is cheepest to the left or to the right.
 * @param born Le premier entier.
 * @param data Le deuxième entier.
 * @param stack stack to process
 * @return OK, NO_MOVE or ERR.
 */
int	get_born(long born[2], t_global_data *data, int stack, int *value)
{
	if (!value || (stack != STACK_A && stack != STACK_B))
		return (ERR);
	if (stack == STACK_A)
	{
		born[LE] = (((long)value - (long)data->a) / 4);
		born[RI] = ft_abs((long)value - ((long)(data->a + (data->size_a - 1))))
			/ sizeof(int) + 1;
		if (value == data->a)
			return (NO_MOVE);
	}
	else if (stack == STACK_B)
	{
		born[LE] = ft_abs(((long)value - (long) data->b) / 4);
		born[RI] = (((long)value - ((long)(data->b - (data->size_b - 1))))
				/ sizeof(int)) + 1;
		if (value == data->b)
			return (NO_MOVE);
	}
	return (OK);
}

int	at_beginning(t_global_data *data, int stack, int *value)
{
	long	born[2];
	int		status;

	status = get_born(born, data, stack, value);
	if (status == ERR)
		return (ERR);
	else if (status == NO_MOVE)
		return (NO_MOVE);
	if (born[LE] > born[RI] || born[LE] == born[RI])
		move(data, stack, rev_rotate, born[RI]);
	else if (born[RI] > born[LE])
		move(data, stack, rotate, born[LE]);
	return (OK);
}

int	move(t_global_data *data, int stack,
	int (f)(t_global_data *, int, int), int counter
)
{
	int	i;

	i = 0;
	if ((stack != STACK_A && stack != STACK_B) || !data || !f)
		return (ERR);
	while (i < counter)
	{
		f(data, stack, DISPLAY);
		i++;
	}
	return (OK);
}
