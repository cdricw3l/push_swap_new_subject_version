/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:06:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 21:46:59 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	init_global_data(char **argv, t_global_data *data)
{
	if (!argv || !*argv)
		return (ERR);
	ft_bzero(data, sizeof(t_global_data));
	data->size_a = check_args(argv, data);
	if (data->size_a == ERR || data->size_a > LIMIT)
	{
		if (data->size_a > LIMIT)
			write(STDOUT_FILENO, "to much arguments max: 1024\n", 16);
		write(STDOUT_FILENO, "Error check arg\n", 16);
		return (ERR);
	}
	if (create_stack(argv, data) == ERR)
	{
		write(STDOUT_FILENO, "Error stack creation\n", 21);
		return (ERR);
	}
	if (check_duplicate(data) == ERR)
	{
		write(STDOUT_FILENO, "Error dupplicate value\n", 23);
		return (ERR);
	}
	data->disorder = compute_disorder(data);
	return (OK);
}
