/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:12:18 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/31 20:12:20 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_split_len(char **split)
{
	size_t	len;

	if (!split)
		return (0);
	len = 0;
	while (split[len])
		len++;
	return (len);
}
