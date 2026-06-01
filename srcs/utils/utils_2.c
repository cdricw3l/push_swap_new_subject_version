/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 09:51:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 20:58:26 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_best_move	*build_best_move(int value, int counter,
	int (f)(t_global_data *, int, int)
)
{
	t_best_move	*best_move;

	best_move = malloc(sizeof(t_best_move));
	if (!best_move)
		return (NULL);
	best_move->value = value;
	best_move->number = counter;
	best_move->move = f;
	return (best_move);
}

int	generate_range(int ranges[LIMIT][2], int total_size)
{
	int	base;
	int	range_start;
	int	range_end;
	int	i;

	if (total_size > LIMIT || total_size < 2)
		return (ERR);
	range_start = 1;
	range_end = total_size / RANGE_SIZE;
	base = total_size / (total_size / RANGE_SIZE);
	i = 0;
	if (total_size % RANGE_SIZE)
		base += 1;
	while (i < base)
	{
		ranges[i][0] = range_start;
		ranges[i][1] = range_end;
		range_start += (total_size / RANGE_SIZE);
		range_end += (total_size / RANGE_SIZE);
		if (i == base - 1 && total_size % RANGE_SIZE > 0)
			ranges[i][1] = ranges[i][0] + (total_size % RANGE_SIZE) - 1;
		i += 1;
	}
	return (i);
}
