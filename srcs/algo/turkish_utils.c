/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:21:03 by mabrugge          #+#    #+#             */
/*   Updated: 2026/06/02 14:01:37 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_total_cost(t_best_cost *target, t_list *list)
{
	t_list		*current;
	t_best_cost	*cur;

	current = list;
	while (current)
	{
		cur = current->content;
		if (cur->value == target->target_value)
			return (cur->number_of_move + target->number_of_move);
		current = current->next;
	}
	return (0);
}
