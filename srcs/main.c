/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/31 19:17:59 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>

int main(int argc, char **argv)
{
    t_global_data data;

    (void)argc;
    if(init_global_data(&argv[1], &data) == ERR)
        return (1);
    while (data.a)
    {
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
    }
    display_stack(&data, STACK_B);
    at_beginning(&data, STACK_B, bigest_value(&data, STACK_B));
    display_stack(&data, STACK_B);
    // if (data.size_a == 2)
    //     two_values(&data, STACK_A);
    // if (data.size_a == 3)
    //     three_values(&data, STACK_A);
    // else if(data.size_a == 5 && data.algo == NONE)
    //   five_values(&data, STACK_A);
    // else if (data.algo == SIMPLE)
    //     selection_sort(&data);
    // medium_rank(&data);
    return (0);
}
