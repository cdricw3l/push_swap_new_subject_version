/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 22:53:48 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/02 01:30:49 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_sort(t_global_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (ERR);
		i++;
	}
	return (OK);
}

int	check_input(char *buffer)
{
	if (!buffer)
		return (ERR);
	if (!ft_strncmp(buffer, "sa\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "sb\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "pa\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "pb\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "ra\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "rb\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "rra\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "rrb\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "rr\n", ft_strlen(buffer)))
		return (OK);
	else if (!ft_strncmp(buffer, "rrr\n", ft_strlen(buffer)))
		return (OK);
	return (ERR);
}

int	dispatch_move(t_global_data *data, char *buffer)
{
	if (!ft_strncmp(buffer, "sa\n", ft_strlen(buffer)))
		return (swap(data, STACK_A));
	else if (!ft_strncmp(buffer, "sb\n", ft_strlen(buffer)))
		return (swap(data, STACK_B));
	else if (!ft_strncmp(buffer, "pa\n", ft_strlen(buffer)))
		return (push(data, STACK_A, STACK_B));
	else if (!ft_strncmp(buffer, "pb\n", ft_strlen(buffer)))
		return (push(data, STACK_B, STACK_A));
	else if (!ft_strncmp(buffer, "ra\n", ft_strlen(buffer)))
		return (rotate(data, STACK_A));
	else if (!ft_strncmp(buffer, "rb\n", ft_strlen(buffer)))
		return (rotate(data, STACK_B));
	else if (!ft_strncmp(buffer, "rra\n", ft_strlen(buffer)))
		return (rev_rotate(data, STACK_A));
	else if (!ft_strncmp(buffer, "rrb\n", ft_strlen(buffer)))
		return (rev_rotate(data, STACK_B));
	else if (!ft_strncmp(buffer, "rr\n", ft_strlen(buffer)))
		return (double_rotation(data, RR));
	else if (!ft_strncmp(buffer, "rrr\n", ft_strlen(buffer)))
		return (double_rotation(data, RRR));
	return (ERR);
}

int	error_managment(char **line, int code)
{
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	if (line && *line)
		free(*line);
	return (code);
}

int	main(int argc, char **argv)
{
	t_global_data	data;
	int				b_read; 
	char			*buffer;

	if (argc == 1)
		return (0);
	if (init_global_data(&argv[1], &data) == ERR)
		return (error_managment(NULL, 1));
	b_read = 1;
	buffer = argv[0];
	while (buffer)
	{
		buffer = get_next_line(STDIN_FILENO, STANDARD_MODE);
		if (!buffer)
			break ;
		if (check_input(buffer) == ERR)
			return (error_managment(&buffer, 255));
		dispatch_move(&data, buffer);
		free(buffer);
	}
	if (ft_is_sort(&data) == OK)
		write(STDOUT_FILENO, "OK\n", ft_strlen("OK\n"));
	else
		write(STDOUT_FILENO, "KO\n", ft_strlen("KO\n"));
	return (OK);
}
