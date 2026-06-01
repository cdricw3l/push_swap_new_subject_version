/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/06/01 20:34:48 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int processing_error_message(int code)
{
	if(code == ERR)
	{
		write(STDOUT_FILENO, "processing error\n", ft_strlen("processing error\n"));
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_global_data	data;

	(void)argc;
	if (init_global_data(&argv[1], &data) == ERR)
		return (1);
	if (ft_is_sort(&data, STACK_A))
		return (OK);
	if (data.size_a == 2)
		argc = two_values(&data, STACK_A);
	if (data.size_a == 3)
		argc = three_values(&data, STACK_A);
	else if (data.size_a == 5 && data.algo == NONE)
		argc = five_values(&data, STACK_A);
	else if (data.algo == SIMPLE)
		argc = selection_sort(&data);
	else if (data.algo == MEDIUM)
		argc = medium_rank(&data);
	if(argc == ERR)
		return (processing_error_message(argc));
	return (OK);
}
