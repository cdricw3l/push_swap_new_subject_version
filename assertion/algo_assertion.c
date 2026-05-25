/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:25:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/25 13:42:01 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void tree_value_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_data data;

    int arr1[3] = {1,2,3};
    int arr2[3] = {1,3,2};
    int arr3[3] = {2,1,3};
    int arr4[3] = {2,3,1};
    int arr5[3] = {3,1,2};
    int arr6[3] = {3,2,1};
    
    data.a = arr1;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr2;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr2;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr4;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr5;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr6;
    tree_values(&data);
    assert(ft_is_sort(&data));
    ASSERT_END(__func__);
}

void buble_sort_assert(char **argv)
{
    ASSERT_START(__func__, __LINE__);
    t_data data;

    assert(argv[1]);
    printf("voici %s\n", argv[1]);
    assert(init_data(&argv[1], &data) == OK);
    int move = ft_buble_sort_push(&data);
    printf("voici le nombre de mouvement: %d\n", move);
    ASSERT_END(__func__);
}

void algo_assert(char **argv)
{
    tree_value_assert();
    buble_sort_assert(argv);
}   