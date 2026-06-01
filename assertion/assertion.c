/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:03:17 by cdric.b           #+#    #+#             */
/*   Updated: 2026/06/01 11:56:40 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int main(void)
{
    char buffer[3];
    char intro[] = "Witch test yould you want to launch:\n \
                    ["GREEN"0"RESET"] = 0_init_and_check_assertion\n \
                    ["GREEN"1"RESET"] = 1_move_assertion\n \
                    ["GREEN"2"RESET"] = 2_at_beginning_assert\n \
                    ["GREEN"3"RESET"] = 3_3_value_assert\n \
                    ["GREEN"4"RESET"] = 4_generate_range_asser\n \
                    ["GREEN"5"RESET"] = 5_5_value_assert\n \
                    ["GREEN"6"RESET"] = 6_best_move_assertion\ninput: ";
    int b_read;

    write(STDOUT_FILENO, intro, ft_strlen(intro));
    b_read = read(STDIN_FILENO, buffer, 3);
    if (b_read < 0 || b_read > 2)
        return (1);
    buffer[b_read - 1] = '\0';
    if(!ft_strncmp("0", buffer, 2))
        init_and_check_assert();
    else if(!ft_strncmp("1", buffer, 2))
        move_assertions();
    else if(!ft_strncmp("2", buffer, 2))
        at_beginning_assert();
    else if(!ft_strncmp("3", buffer, 2))
        three_value_assert();
    else if(!ft_strncmp("4", buffer, 2))
        generate_range_assert();
    else if(!ft_strncmp("5", buffer, 2))
        five_value_assert();
    else if(!ft_strncmp("6", buffer, 2))
        best_move_assert();

    return (0);
}