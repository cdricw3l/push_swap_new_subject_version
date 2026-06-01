#include "generateur_x_y.h"

char *get_complete_path(char *test_file)
{
    char *complete_path;

    if(!test_file)
        return (NULL);
    complete_path = ft_strjoin(INPUT_PATH, test_file);
    if(!complete_path)
        return (NULL);
    return(complete_path);
}

char *get_output_path(char *test_file)
{
    char *output_path;
    char *complet_output_path;
    char **split;
    size_t split_len;

    if(!test_file)
        return (NULL);
    split = ft_split(test_file, '/');
    if(!split)
        return (NULL);
    split_len = ft_split_len(split);
    output_path = ft_strjoin(OUPUT_PATH, split[split_len - 1]);
    ft_split_clean(&split);
    if(!output_path)
        return (NULL);
    complet_output_path = ft_strjoin(output_path, ".output");
    free(output_path);
    if(!complet_output_path)
        return (NULL);
    return(complet_output_path);
}


char **get_list_file(char *path)
{
    
    DIR *dir;
    size_t len;
    struct dirent *dp;
    char **list_file;
    int i;
    long position;
    dir = opendir(path);
    if(!dir)
    {
        perror("opendir");
        return (NULL);
    }
    len = 0;
    position = telldir(dir);
    while((dp = readdir(dir)) != NULL)
    {
        if(!strcmp(".", dp->d_name) || !strcmp("..", dp->d_name))
            continue;
        len++;
    }
    seekdir(dir, position);
    list_file = malloc(sizeof(char *) * (len + 1));
    if(!list_file)
    {
        closedir(dir);
        return(NULL);
    }
    i = 0;
    while((dp = readdir(dir)) != NULL)
    {
        if(!strcmp(".", dp->d_name) || !strcmp("..", dp->d_name))
            continue;
        else
            list_file[i++] = strdup(dp->d_name);
    }
    list_file[i] = NULL;
    closedir(dir);
    return (list_file);
}


