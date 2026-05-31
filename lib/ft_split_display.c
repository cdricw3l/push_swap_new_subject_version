/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:12:09 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/31 20:12:11 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_display(char **split, int fd)
{
	char	**ptr;

	if (!split)
		return ;
	ptr = split;
	while (*ptr)
	{
		ft_putendl_fd(*ptr, fd);
		ptr++;
	}
}
