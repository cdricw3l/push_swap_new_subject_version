/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:29:56 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/02 15:00:52 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void write_bench(void)
{
    write(STDERR_FILENO, "[bench] ", ft_strlen("[bench] "));
}



void write_strategy(t_global_data *data)
{
    write(STDERR_FILENO, "strategy: ", ft_strlen("strategy: "));
    if(data->strategy == SIMPLE)
       write(STDERR_FILENO, "Simple / O(n2)\n", ft_strlen("Simple / O(n2)\n"));
    if(data->strategy == MEDIUM)
       write(STDERR_FILENO, "Medium / O(n√n)\n", ft_strlen("Medium / O(n√n)\n"));
    if(data->strategy == COMPLEX)
       write(STDERR_FILENO, "Complex / O(n log n)\n", ft_strlen("Complex / O(n log n)\n"));
    if(data->strategy == ADAPTATIVE)
    {
        write(STDERR_FILENO, "Adaptive / ", ft_strlen("Adaptive / "));
        if (data->disorder < 0.2)
            write(STDERR_FILENO, "O(n2)\n", ft_strlen("O(n2)\n"));
        else if (data->disorder >= 0.2 && data->disorder < 0.5)
             write(STDERR_FILENO, "O(n√n)\n", ft_strlen("O(n√n)\n"));
        else if (data->disorder > 0.5)
            write(STDERR_FILENO, "O(n log n)\n", ft_strlen("O(n log n)\n"));
    }
}
void write_disorder(t_global_data *data)
{
    write(STDERR_FILENO,"disorder: ", ft_strlen("disorder: "));
    put_float(data->disorder);
    write(STDERR_FILENO,"%\n", ft_strlen("%\n"));

}

void write_total_ops(t_global_data *data)
{
    write(STDERR_FILENO, "total_ops: ", ft_strlen("total_ops: "));
    ft_putnbr_fd(data->total_ops, STDERR_FILENO);
    write(STDERR_FILENO,"\n", 1);
}

void write_move_ops(t_global_data *data)
{
    ft_putstr_fd("sa: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[SA], STDERR_FILENO);
    ft_putstr_fd(" sb: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[SB], STDERR_FILENO);
    ft_putstr_fd(" pa: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[PA], STDERR_FILENO);
    ft_putstr_fd(" pb: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[PB], STDERR_FILENO);
    ft_putendl_fd("", STDERR_FILENO);
    ft_putstr_fd("ra: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[RA], STDERR_FILENO);
    ft_putstr_fd(" rb: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[RB], STDERR_FILENO);
    ft_putstr_fd(" rr: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[RR], STDERR_FILENO);
    ft_putstr_fd(" rra: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[RRA], STDERR_FILENO);
    ft_putstr_fd(" rrb: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[RRB], STDERR_FILENO);
    ft_putstr_fd(" rrr: ", STDERR_FILENO);
    ft_putnbr_fd(data->move_count[RRR], STDERR_FILENO);
    ft_putendl_fd("", STDERR_FILENO);
}

int benchmark(t_global_data *data)
{
    if(!data)
        return (ERR);
    write_bench();
    write_disorder(data);
    write_bench();
    write_strategy(data);
    write_bench();
    write_total_ops(data);
    write_bench();
    write_move_ops(data);
    return (OK);
}