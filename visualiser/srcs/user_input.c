#include "generateur_x_y.h"

int clean_io(t_IO **io, int code)
{

    if (!io)
        return (1);
    if ((*io)->path_input_file)
    {
        free((*io)->path_input_file);
        (*io)->path_input_file = NULL;
    }
    if ((*io)->path_output_file)
    {
        free((*io)->path_output_file);
        (*io)->path_output_file = NULL;
    }
    if ((*io)->fd_input > -1)
        close((*io)->fd_input);
    if ((*io)->fd_output > -1)
        close((*io)->fd_output > -1);
    return (code);
}

static int check_input_user(char *buffer)
{
    int i;

    i = 0;
    if(!buffer)
        return (ERR);
    while (buffer[i])
    {
        if(!isdigit(buffer[i]))
        {
            printf(C_RED"Bad test number: only digit are allowed"C_RESET"\n");
            return (ERR);
        }
        i++;
    }
    return (OK);
}

int check_output_folder(void)
{
    if(access("output", W_OK) < 0)
    {
        if(mkdir("output", 0755) < 0)
        {
            printf(C_RED"The folder output doesn't exist and we can't create him"C_RESET"\n");
            return (ERR);
        }
    }
    return (OK);
}

int get_file_descriptor(t_IO *io)
{
    if(check_output_folder() == ERR)
        return (ERR);
    if(!io->path_input_file || !io->path_output_file)
    {
        printf(C_RED"Path error we can't open files"C_RESET"\n");
        return (ERR);
    }
    io->fd_input = open(io->path_input_file, O_RDONLY);
    if(io->fd_input < 0)
        return (ERR);
    io->fd_output =  open(io->path_output_file, O_WRONLY | O_CREAT , 0755);
    if(io->fd_output < 0)
    {
        close(io->fd_input);
        return (ERR);
    }
    return (1);
}

int chose_your_test_file(char **file_list, t_IO *io)
{
    int i;
    int b_read;
    size_t nb_file;
    int user_input;
    char buffer[1024];

    if(!file_list)
        return (ERR);
    nb_file = ft_split_len(file_list);
    if(nb_file < 1)
        return (ERR);
    printf(C_GREEN"Choose your test file between 1 and %zu"C_RESET"\n", nb_file);
    i = 0;
    while (file_list[i])
    {
        printf("[%d] %s\n", i + 1, file_list[i]);
        i++;
    }
    write(STDOUT_FILENO,"Enter a number test: ", strlen("Enter a number test: "));
    b_read = read(STDIN_FILENO, buffer, 1023);
    if(b_read < 0)
        return(ERR);
    buffer[b_read - 1] = '\0';
    if(check_input_user(buffer) == ERR)
        return (ERR);
    user_input = atoi(buffer);
    if(user_input < 1 || user_input > (int)nb_file)
    {
        printf(C_RED"Bad test number input chose test between %d and %zu"C_RESET"\n", 1, nb_file);
        return (ERR);
    }
    io->path_input_file = get_complete_path(file_list[user_input - 1]);
    if(!io->path_input_file)
    {
        printf(C_RED"Error creation input path function: %s line:%d"C_RESET"\n", __func__, __LINE__);
        return (clean_io(&io, ERR));
    }
    io->path_output_file = get_output_path(io->path_input_file);  
    if(!io->path_output_file)
    {
        printf(C_RED"Error creation output path function: %s line:%d"C_RESET"\n", __func__, __LINE__);
        return (clean_io(&io, ERR));
    }
    if(get_file_descriptor(io) == ERR)
        return (clean_io(&io, ERR));
    return (OK);
}