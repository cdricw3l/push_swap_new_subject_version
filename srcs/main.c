/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/06/02 11:44:56 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	processing_message(int code)
{
	if (code == ERR)
	{
		write(STDOUT_FILENO, "processing error\n",
			ft_strlen("processing error\n"));
		return (1);
	}
	return (0);
}

int	processing(t_global_data *data)
{
	int	status;

	status = OK;
	if (data->algo == 2 && data->algo == NONE)
		status = two_values(data, STACK_A);
	else if (data->size_a == 3 && data->algo == NONE)
		status = three_values(data, STACK_A);
	else if (data->size_a == 5 && data->algo == NONE)
		status = five_values(data, STACK_A);
	else if (data->algo == SIMPLE)
		status = selection_sort(data);
	else if (data->algo == MEDIUM)
		status = medium_rank(data);
	return (processing_message(status));
}

int	main(int argc, char **argv)
{
	t_global_data	data;
	int				status;
	
	(void)argc;
	if (init_global_data(&argv[1], &data) == ERR)
		return (1);
	if (ft_is_sort(&data, STACK_A))
		return (OK);
	status = processing(&data);
	return (status);
}
