/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_at_beginning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 07:48:46 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/27 07:49:34 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int *get_bigest_value(t_global_data *data, int stack)
{
	int *arr;
	int *p1;
	int i = INT_MIN;

	p1 = &i;
	if (stack == STACK_A)
	{
		arr = data->a;
		while (arr <= data->end)
		{
			if(*arr > *p1)
				p1 = arr;
			arr++;
		}
	}
	else if(stack == STACK_B)
	{
		arr = data->b;
		while (arr >= data->start)
		{
			if(*arr > *p1)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}

int	max_at_beginning(t_global_data *data, int stack)
{
	long 	born[2];
	int 	status;

	status = get_born(born, data, stack);
	printf("move for left %ld move pour right: %ld\n", born[LEFT], born[RIGHT]);
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