#ifndef ASSERTION_H
#define ASSERTION_H

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/push_swap.h"


#define ASSERT_START(msg, line) printf(YELLOW"Test assertion %s line: %d" RESET"\n", msg, line)
#define ASSERT_END(msg) printf(GREEN"End assertion %s --> Ok!"RESET"\n", msg)

int     init_and_check_assert(void);
void    move_assertions(void);
int     at_beginning_assert(void);
void    three_value_assert(void);
void    generate_range_assert(void);
int     five_value_assert(void);
void    best_move_assert(void);

void display_stack(t_global_data *data, int stack);
int check_args(char **argv, t_global_data *data);
int check_digit(char *str);
int get_complexity(char *arg);
int check_args(char **argv, t_global_data *data);
int create_stack(char **argv, t_global_data *data);
int check_duplicate(t_global_data *data);
int init_global_data(char **argv, t_global_data *data);
void display_data(t_global_data data);
int check_range_assert(int ranges[1024][2], int values, int size);
void display_range(int ranges[1024][2], int size);
void generate_range_assert();

#endif