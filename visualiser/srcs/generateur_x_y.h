#ifndef GENERATEUR_X_Y_H
#define GENERATEUR_X_Y_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl/get_next_line_bonus.h"
#include "../../lib/libft.h"
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#define INPUT_PATH "generateur/listes/"
#define OUPUT_PATH "output/"
#define B_SIZE 4096
#define ERR -1
#define OK 1

#define C_RED "\e[0;31;1m"
#define C_GREEN "\e[0;32;1m"
#define C_CYAN "\e[0;36;1m"
#define C_YBG "\e[0;43;1m" //yellow bg
#define C_BBG "\e[0;44;1m" // blue bg
#define C_GBG "\e[2;42;1m" //green bg
#define C_PBG "\e[0;45;1m" //purple bg
#define C_RESET "\e[0m"
#define NEW_LINE write(STDOUT_FILENO, "\n", 1)
#define DEBBUG printf(C_RED"HEREEEE"C_RESET"\n")

typedef struct S_IO
{
    char *path_input_file;
    char *path_output_file;
    int fd_input;
    int fd_output;

} t_IO;


/* user IO */

int chose_your_test_file(char **file_list, t_IO *io);
char *get_output_path(char *test_file);
void display_data(t_IO data);
int clean_io(t_IO **io, int code);
/* test file managment */

char **get_list_file(char *path);
char *get_complete_path(char *test_file);



#endif