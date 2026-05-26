/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:25:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 10:44:26 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void tree_value_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;

    int arr1[3] = {1,2,3};
    int arr2[3] = {1,3,2};
    int arr3[3] = {2,1,3};
    int arr4[3] = {2,3,1};
    int arr5[3] = {3,1,2};
    int arr6[3] = {3,2,1};
    
    data.a = arr1;
    data.size_a = 3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr2;
    data.size_a = 3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr2;
    data.size_a = 3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr3;
    data.size_a = 3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr4;
    data.size_a = 3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr5;
    data.size_a = 3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr6;
    data.size_a = 3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    ASSERT_END(__func__);
}

void five_value_assert(char **argv)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;

    assert(argv[1]);
    assert(init_global_data(&argv[1], &data) == OK);
    if(data.size_a != 5)
    {
        printf(RED"ERREUR: la liste a une taille differente de 5"RESET"\n");
        return ;
    }
    five_values(&data);
    assert(ft_is_sort(&data));
    ASSERT_END(__func__);
}

void min_at_beg_asser(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int smallest;
    char *l1[] = {"1 5 2 4 3", NULL};
    char *l2[] = {"1 -5 20 40 3", NULL};
    char *l3[] = {"1 -5 20 40 3", NULL};
    char *l4[] = {"1 5 -20 40 3 0 78 44 58", NULL};
    char *l5[] = {"1 5 -20 -40 3 220 31 7 88 22", NULL};


    assert(init_global_data(l1, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    min_at_beginning(&data, STACK_A);
    assert(smallest == *data.a);
    free(data.stack);
    
    assert(init_global_data(l2, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    min_at_beginning(&data, STACK_A);
    assert(smallest == *(data.a));
    free(data.stack);
    
    assert(init_global_data(l3, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    min_at_beginning(&data, STACK_A);
    assert(smallest == *data.a);
    free(data.stack);

    assert(init_global_data(l4, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    min_at_beginning(&data, STACK_A);
    assert(smallest == *data.a);
    free(data.stack);
    
    assert(init_global_data(l5, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    min_at_beginning(&data, STACK_A);
    assert(smallest == *data.a);
    free(data.stack);
    ASSERT_END(__func__);
}

void algo_assert(char **argv)
{
    (void)argv;
    min_at_beg_asser();
    tree_value_assert();
    five_value_assert(argv);
}   