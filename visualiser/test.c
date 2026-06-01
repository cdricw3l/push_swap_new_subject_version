/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 21:31:39 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/30 22:27:15 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generateur.h"

int main(void)
{

    pid_t pid;
    int tube[2];

    if (pipe(tube) < 0)
        return (1);
    pid = fork();
    if (pid < 0)
    {
        close(tube[0]);
        close(tube[1]);
        return (1);
    }
    if(pid == 0)
    {
        char *arg[] = {"ls", "-l", NULL};
        if(execve("cat", arg, NULL) < 0)
        {
            perror("Excve_2");
            exit(1);
        }
    }
    return (1);
}