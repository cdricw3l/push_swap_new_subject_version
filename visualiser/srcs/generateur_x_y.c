#include "generateur_x_y.h"

#define PIPE_ERR 1
#define FORK_ERR 2
#define WAIT_ERR 3
#define EXCVE_PUSH_ERR 4
#define EXCVE_WC_ERR 5

int exec_all_list(char *line, t_IO *io)
{
    pid_t pid1;
    pid_t pid2;
    int tube[2];
    int status;

    if(pipe(tube) < 0)
        return (ERR);
    pid1 = fork();
    if (pid1 < 0)
    {
        perror("fork:");
        return (ERR);
    }
    if(pid1 == 0)
    {
        close(tube[0]);
        dup2(tube[1], STDOUT_FILENO);
        close(tube[1]);
        char *arg[] = {"push_swap", "--medium", line, NULL};
        if(execve("../push_swap", arg, NULL) < 0)
        {
            perror("Excve_1");
            exit(EXCVE_PUSH_ERR);
        }
    }
    pid2 = fork();
    if (pid2 < 0)
    {
        perror("fork:");
        return (ERR);
    }
    if(pid2 == 0)
    {
        close(tube[1]);
        dup2(tube[0], STDIN_FILENO);
        dup2(io->fd_output, STDOUT_FILENO);
        close(tube[0]);
        
        char *arg[] = {"wc", "-l", NULL};
        if(execve("/usr/bin/wc", arg, NULL) < 0)
        {
            perror("Excve_2");
            exit(EXCVE_WC_ERR);
        }
    }
    close(tube[0]);
    close(tube[1]);
    waitpid(pid1, &status, 0);
    if(WIFSIGNALED(status))
    {
        printf("%d\n", WTERMSIG(status));
        write(io->fd_output, "Erreur d'execution\n", ft_strlen("Erreur d'execution\n"));
    }
    waitpid(pid2, &status, 0);
    if(!WIFEXITED(status))
    {
        perror("err");
        return (WEXITSTATUS(status));
    }
    return (OK);
}

int display_x(char *line, int fd)
{
    char *x;
    size_t len;
    char **value;

    value = ft_split(line, 32);
    if(!value)
        return (ERR);
    len = ft_split_len(value);
    ft_split_clean(&value);
    if(!len)
        return (ERR);
    x = ft_itoa(len);
    if(!x)
        return (ERR);
    write(fd, x, ft_strlen(x));
    write(fd, " ", 1);
    free(x);
    return(OK);
}


void display_data(t_IO data)
{
    if (data.path_input_file)
        printf("input file: %s file descriptor: %d\n", data.path_input_file, data.fd_input);
    else
        printf("No input file");
    if(data.path_output_file)
        printf("output file %s file descriptor: %d\n", data.path_output_file, data.fd_output);    
    NEW_LINE;
}




int main(void)
{
    t_IO io;
    char *line;
    size_t len;
    char buffer[B_SIZE];
    int fd;
    int status;

    ft_bzero(&io, sizeof(t_IO));
    char **list_file = get_list_file(INPUT_PATH);
    if(chose_your_test_file(list_file, &io) == ERR)
    {
        printf("Erreur chose file\n");
        return (1);
    }
    ft_split_clean(&list_file);
    fd = open(io.path_input_file, O_RDONLY);
    
    len = 1;
    ft_bzero(buffer, B_SIZE);
    while((line = get_next_line(io.fd_input, STANDARD_MODE)) != NULL)
    {
        if(!line)
        {
            close(fd);
            return (1);
        }
        len = ft_strlen(line);
        ft_strlcpy(buffer, line, len + 1);
        free(line);
        if(ft_indexof(buffer, '\n') > -1)
            buffer[ft_indexof(buffer, '\n')] = 0;
        if(display_x(buffer, io.fd_output) == ERR)
        {
            get_next_line(fd, CLEAN_MODE);
            close(fd);
            return (1);
        }
        status = exec_all_list(buffer, &io);
        if(status!= OK)
        {
            get_next_line(fd, CLEAN_MODE);
            printf("exectutsion error\n");
            return (1);
        }
    }
    close(fd);
    return (0);
}