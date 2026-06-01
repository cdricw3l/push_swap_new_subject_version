/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/06/02 01:21:00 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	processing_error_message(int code)
{
	if (code == ERR)
	{
		write(STDOUT_FILENO, "processing error\n",
			ft_strlen("processing error\n"));
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_global_data	data;
	int				r;

	(void)argc;
	r = OK;
	if (init_global_data(&argv[1], &data) == ERR)
		return (1);
	if (ft_is_sort(&data, STACK_A))
		return (OK);
	if (data.size_a == 2 && data.algo == NONE)
		r = two_values(&data, STACK_A);
	else if (data.size_a == 3 && data.algo == NONE)
		r = three_values(&data, STACK_A);
	else if (data.size_a == 5 && data.algo == NONE)
		r = five_values(&data, STACK_A);
	else if (data.algo == SIMPLE)
		r = selection_sort(&data);
	else if (data.algo == MEDIUM)
		r = medium_rank(&data);
	if (r == ERR)
		return (processing_error_message(r));
	return (OK);
}
