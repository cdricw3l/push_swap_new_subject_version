/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:11:29 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 18:31:26 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_complexity(char *arg)
{
	if (ft_strncmp(arg, "--simple",
			ft_strlen_longest("--simple", arg)) == OK)
		return (SIMPLE);
	else if (ft_strncmp(arg, "--medium",
			ft_strlen_longest("--medium", arg)) == OK)
		return (MEDIUM);
	else if (ft_strncmp(arg, "--complex",
			ft_strlen_longest("--complex", arg)) == OK)
		return (COMPLEX);
	else if (ft_strncmp(arg, "--adaptive",
			ft_strlen_longest("--adaptive", arg)) == OK)
		return (ADAPTATIVE);
	return (NONE);
}

float	compute_disorder(t_global_data *data)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			total_pairs++;
			if (data->stack[i] > data->stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

int	ft_is_sort(t_global_data *data, int stack)
{
	int				i;
	t_stack_data	stk;

	if (get_stack_data(data, stack, &stk) == ERR)
		return (-1);
	i = 0;
	while (i < stk.len - 1)
	{
		if (stack == STACK_A)
		{
			if (*(stk.arr) > *(stk.arr + 1))
				return (0);
			stk.arr++;
		}
		else if (stack == STACK_B)
		{
			if (*(stk.arr) < *(stk.arr - 1))
				return (0);
			stk.arr--;
		}
		i++;
	}
	return (1);
}

int	get_stack_data(t_global_data *data, int stack, t_stack_data *stk)
{
	if (!data || (stack != STACK_A && stack != STACK_B))
		return (ERR);
	if (stack == STACK_A)
	{
		stk->arr = data->a;
		stk->len = data->size_a;
	}
	else if (stack == STACK_B)
	{
		stk->arr = data->b;
		stk->len = data->size_b;
	}
	return (OK);
}

int	check_range(int ranges[1024][2], int values, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		count += (ranges[i][1] - ranges[i][0]) + 1;
		i++;
	}
	if (count != values)
		write(STDOUT_FILENO, "Error in creation range\n",
			ft_strlen("Error in creation range\n"));
	return (OK);
}
