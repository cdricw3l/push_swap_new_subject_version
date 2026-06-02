/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrugge <mabrugge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:11:29 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/02 11:40:36 by mabrugge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_swap(int *p1, int *p2)
{
	int	tmp;

	if (!p1 || !p2)
		return ;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int	get_complexity(char *arg)
{
	if (ft_strncmp(arg, "--simple", ft_strlen_longest("--simple", arg)) == OK)
		return (SIMPLE);
	else if (ft_strncmp(arg, "--medium", ft_strlen_longest("--medium",
				arg)) == OK)
		return (MEDIUM);
	else if (ft_strncmp(arg, "--complex", ft_strlen_longest("--complex",
				arg)) == OK)
		return (COMPLEX);
	else if (ft_strncmp(arg, "--adaptive", ft_strlen_longest("--adaptive",
				arg)) == OK)
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

	if (get_stack_data(*data, stack, &stk) == ERR)
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

int	get_stack_data(t_global_data data, int stack, t_stack_data *stk)
{
	if (stack == STACK_A)
	{
		stk->arr = data.a;
		stk->len = data.size_a;
	}
	else if (stack == STACK_B)
	{
		stk->arr = data.b;
		stk->len = data.size_b;
	}
	else
		return (ERR);
	return (OK);
}

int	get_target_number(t_global_data *data, int stack, t_list **lst)
{
	t_stack_data	stk;
	t_list			*new_node;
	t_best_cost		*best;
	int				i;

	i = 0;
	get_stack_data(*data, stack, &stk);
	while (i < stk.len)
	{
		best = malloc(sizeof(t_best_cost));
		if (!best)
			return (free_list(lst), ERR);
		if (stack == STACK_A)
			init_best_cost(best, data, stack, stk.arr + i);
		else
			init_best_cost(best, data, stack, stk.arr - i);
		new_node = ft_lstnew(best);
		if (!new_node)
			return (free(best), free_list(lst), ERR);
		ft_lstadd_back(lst, new_node);
		i++;
	}
	return (OK);
}

void	set_move(t_best_cost *best, long born[2])
{
	if (born[LEFT] <= born[RIGHT])
	{
		best->move = rev_rotate;
		best->number_of_move = born[LEFT];
	}
	if (born[RIGHT] < born[LEFT])
	{
		best->move = rotate;
		best->number_of_move = born[RIGHT];
	}
}

void	init_best_cost(t_best_cost *best, t_global_data *data, int stack,
		int *ptr)
{
	long	born[2];

	get_born(born, data, stack, ptr);
	best->value = *ptr;
	best->address_ptr_value = ptr;
	best->stack = stack;
	set_move(best, born);
}

void	free_list(t_list **list)
{
	t_list		*tmp;
	t_best_cost	*content;

	while (*list)
	{
		tmp = (*list)->next;
		content = (*list)->content;
		free(content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}
