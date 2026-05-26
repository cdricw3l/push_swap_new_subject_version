/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:25:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 13:12:57 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void tree_value_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;

    /* case 0 */
    // int arr1[6] = {3, 2, 1, 4, 5, 6};
    
    // data.a = &arr1[3];
    // data.b = &arr1[2];
    // data.size_a = 3;
    // data.size_b = 3;
    // data.start = &arr1[0];
    // data.end = &arr1[5];
    
    // assert(tree_values(&data, STACK_A) == NO_MOVE);
    // assert(tree_values(&data, STACK_B) == NO_MOVE);

    // assert(ft_is_sort(&data, STACK_A));
    // assert(ft_is_sort(&data, STACK_B));
    
    /* case 1 */
    int arr2[6] = {5 ,6 ,4, 1, 3, 2};
    data.a = &arr2[3];
    data.b = &arr2[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr2[0];
    data.end = &arr2[5];

    assert(tree_values(&data, STACK_A) == OK);
    assert(tree_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    
   
    // /* case 2 */
    int arr3[6] = {6 ,4 ,5, 2, 1, 3};
    data.a = &arr3[3];
    data.b = &arr3[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr3[0];
    data.end = &arr3[5];

    assert(tree_values(&data, STACK_A) == OK);
    assert(tree_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));

     

    /* case 3 */
    int arr4[6] = {4 ,6 ,5, 2, 3, 1};
    data.a = &arr4[3];
    data.b = &arr4[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr4[0];
    data.end = &arr4[5];

    display_stack(&data, STACK_A);
    assert(tree_values(&data, STACK_A) == OK);
    display_stack(&data, STACK_A);
    assert(tree_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    
    /* case 4 */
    
    /*
        case 0: 3 4 5; 
        case 1: 3 5 4; 
        case 2: 4 3 5;

        case 3: 4 5 3;
        case 4: 5 3 4; 
        case 5: 5 4 3
    */

    
    //  int arr5[6] = {5 ,4 ,6, 3, 1, 2};
    // data.a = &arr5[3];
    // data.b = &arr5[2];
    // data.size_a = 3;
    // data.size_b = 3;
    // data.start = &arr5[0];
    // data.end = &arr5[5];

    // assert(tree_values(&data, STACK_A) == OK);
    // assert(tree_values(&data, STACK_B) == OK);

    // assert(ft_is_sort(&data, STACK_A));
    // assert(ft_is_sort(&data, STACK_B));
    
    // tree_values(&data, STACK_A);
    // tree_values(&data, STACK_B);

    // assert(ft_is_sort(&data, STACK_A));
    // assert(ft_is_sort(&data, STACK_B));
    
    // data.a = arr3;
    // data.b = arr33;
    // data.size_a = 3;
    // data.size_b = 3;
    
    // tree_values(&data, STACK_A);
    // tree_values(&data, STACK_B);
    
    // assert(ft_is_sort(&data, STACK_A));
    // assert(ft_is_sort(&data, STACK_B));

    // data.a = arr4;
    // data.a = arr44;
    // data.size_a = 3;
    // data.size_b = 3;
    
    // tree_values(&data, STACK_A);
    // tree_values(&data, STACK_B);

    // assert(ft_is_sort(&data, STACK_A));
    // assert(ft_is_sort(&data, STACK_B));
    
    // data.a = arr5;
    // data.b = arr55;
    // data.size_a = 3;
    // data.size_b = 3;
    
    // tree_values(&data, STACK_A);
    // tree_values(&data, STACK_B);

    // assert(ft_is_sort(&data, STACK_A));
    // assert(ft_is_sort(&data, STACK_B));
    
    // data.a = arr6;
    // data.b = arr66;
    // data.size_a = 3;
    // data.size_b = 3;
    
    // tree_values(&data, STACK_A);
    // tree_values(&data, STACK_B);

    // assert(ft_is_sort(&data, STACK_A));
    // assert(ft_is_sort(&data, STACK_B));
    
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
    five_values(&data, STACK_A);
    assert(ft_is_sort(&data, STACK_A));
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
    
    assert(min_at_beginning(&data, STACK_A) == NO_MOVE);
    assert(smallest == *data.a);
   
    
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
    //min_at_beg_asser();
    tree_value_assert();
    //five_value_assert(argv);
}   