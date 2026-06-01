/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/06/01 13:16:10 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_global_data	data;

	(void)argc;
	if (init_global_data(&argv[1], &data) == ERR)
		return (1);
	if (data.size_a == 2)
		two_values(&data, STACK_A);
	if (data.size_a == 3)
		three_values(&data, STACK_A);
	else if (data.size_a == 5 && data.algo == NONE)
		five_values(&data, STACK_A);
	else if (data.algo == SIMPLE)
		selection_sort(&data);
	else if (data.algo == MEDIUM)
		medium_rank(&data);
	//display_stack(&data, STACK_A);
	return (0);
}
