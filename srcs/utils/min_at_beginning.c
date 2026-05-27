/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_at_beginning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:27:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 09:03:39 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


long ABS(long value)
{
	if(value < 0)
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

int get_born(long born[2], t_global_data *data, int stack, int *(get_value)(t_global_data *, int))
{
	int		*value;

	value = get_value(data, stack);
	if (!value || (stack != STACK_A && stack != STACK_B))
		return (ERR);
	if (stack == STACK_A)
	{
		born[LEFT] = (((long)value - (long)data->a) / 4);
		born[RIGHT] = ABS(((long)value - (long)(data->a + (data->size_a - 1))) / sizeof(int)) + 1;
		if (value == data->a)
			return(NO_MOVE);
	}
	else if (stack == STACK_B)
	{
		born[LEFT]  = ABS(((long)value - (long) data->b) / 4);
		born[RIGHT]  = (((long)value - ((long) (data->b - (data->size_b - 1)))) / sizeof(int)) + 1;
		if (value == data->b)
			return(NO_MOVE);
	}
	return (OK);
}

int	min_at_beginning(t_global_data *data, int stack)
{
	long 	born[2];
	int 	status;

	status = get_born(born, data, stack, get_smalest_value );
	if(status == ERR)
		return (ERR);
	else if(status == NO_MOVE)
		return (NO_MOVE);
	if (born[LEFT] < 0)
		born[LEFT] = born[LEFT] *-1;
	if (born[RIGHT] < 0)
		born[RIGHT] = born[RIGHT] *-1;
	if (born[LEFT] > born[RIGHT] || born[LEFT] == born[RIGHT])
		while (born[RIGHT] > 0)
		{
			rotate(data, stack, DISPLAY);
			born[RIGHT]--;
		}
	else if(born[RIGHT] > born[LEFT])
		while (born[LEFT] > 0)
		{
			rev_rotate(data, stack, DISPLAY);
			born[LEFT]--;
		}
	return (OK);
}

int *get_smalest_value(t_global_data *data, int stack)
{
	int *arr;
	int *p1;
	int i = INT_MAX;

	p1 = &i;
	if (stack == STACK_A)
	{
		arr = data->a;
		while (arr <= data->end)
		{
			if(*arr < *p1)
				p1 = arr;
			arr++;
		}
	}
	else if(stack == STACK_B)
	{
		arr = data->b;
		while (arr >= data->start)
		{
			if(*arr < *p1)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}




