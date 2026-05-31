/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_assert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:54:17 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/31 23:24:36 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

/*
    1 2 3 4
    1 2 4 3
    1 3 2 4
    1 3 4 2
*/
int check_range_assert_v2(int ranges[1024][2], int values, int size)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    while (i < size)
    {
        count += (ranges[i][1] - ranges[i][0]) + 1;
        printf("%d\n", (ranges[i][1] - ranges[i][0]) + 1);
        i++;
    }
    printf("voici le count %d et value %d\n", count, values);
    assert(count == values);
    return (OK);
}


void display_ranges(int ranges[1024][2], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("range: %d to %d\n", ranges[i][0] , ranges[i][1]);
        i++;
    }
    
}

int four(void)
{
    t_global_data data;
    t_best_move *best;
    int ranges[LIMIT][2];
    int nb_range;
    int i;

    char *str[] = {"8 5 7 4 12 3 2 22 11 6 17 10 1 9 15 20 21  18 14 19 16 13", NULL};
    assert(init_global_data(str,&data) == OK);
    assert(data.size_a == 22);
    nb_range = generate_range_v2(ranges, data.size_a);
    display_ranges(ranges, nb_range);
    check_range_assert_v2(ranges, data.size_a,  nb_range);
    i = 0;
    while (i < nb_range)
    {
        printf("range: %d to %d\n", ranges[i][0] , ranges[i][1]);
        if(data.size_a == 2)
            two_values(&data, STACK_A);
        else if(data.size_a == 3)
            three_values(&data, STACK_A);
        else
        {
            best = best_move(&data, ranges[i]);
            while(best != NULL)
            {
                move(&data, STACK_A, best->move, best->number);
                free(best);
                push(&data, STACK_A, STACK_B, DISPLAY);

                best = best_move(&data, ranges[i]);
            }

            push(&data, STACK_B, STACK_A, DISPLAY);
            push(&data, STACK_B, STACK_A, DISPLAY);
            
            if(data.a && *(data.a) < *(data.a + 1))
                swap(&data, STACK_A, DISPLAY);
            if(data.b && *(data.b) < *(data.b - 1))
                swap(&data, STACK_B, DISPLAY);
            
            display_stack(&data, STACK_B);
            display_stack(&data, STACK_A);
            printf("voici imedia %d de %d\n", *immediat_superior(&data, STACK_B, data.a), *data.a);
            at_beginning(&data, STACK_B, immediat_superior(&data, STACK_B, data.a));
           
            push(&data, STACK_A, STACK_B,DISPLAY);
            push(&data, STACK_A, STACK_B,DISPLAY);
            display_stack(&data, STACK_B);
            display_stack(&data, STACK_A);
            if(i == 1)
                assert(1 == 2);
           

            
          
        }
        
        i++;
    }
    at_beginning(&data, STACK_B, bigest_value(&data,STACK_B));
    
    display_stack(&data, STACK_B);

    return (OK);
}