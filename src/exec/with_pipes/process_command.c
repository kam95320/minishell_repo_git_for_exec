/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:35:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/05 13:55:39 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"
#include "internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// void	ft_perror_fork(void)
// {
// 	perror("fork failed");
// 	exit(EXIT_FAILURE);
// }

// void	process_commands(t_commande **commands, char ***envp, t_fd *fds)
// {
// 	pid_t	pid;

// 	fds->i = 0;
// 	fds->fd_infile = command_get_fd_infile(commands[fds->i]);
// 	while (commands[fds->i] != NULL)
// 	{
// 		int j;
// 		j = 0;
// 		// printf("%s\n", commands[fds -> i] -> name);	
// 		printf("name = %s\n", commands[fds -> i] -> args[j]);
// 		printf("infile  = %d\n", fds->fd_infile);
// 		printf("outfile =  %d\n\n\n", fds->fd_outfile);
		
// 		for (int j = 0; commands[fds->i]->args[j] != NULL; j++)
// 		{
//     		printf("Argument %d: %s\n", j, commands[fds->i]->args[j]);
// 		}

// 		// printf("%d\n", commands[fds -> i] -> outfiles);
// 		if (commands[fds->i + 1] != NULL)
// 			pipe_fd(fds->fd);
// 		if (commands[fds->i + 1] == NULL)
// 			fds->fd_outfile = command_get_fd_outfile(commands[fds->i]);
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			child_process(fds->fd_infile, fds->fd_outfile, commands, fds);
// 			ft_exec(commands, fds->i, envp);
// 		}
// 		else if (pid > 0)
// 			else_if_in_child_process(&fds->fd_infile, commands, fds->i,
// 				fds->fd);
// 		else
// 			ft_perror_fork();
// 		fds->i++;
// 	}
// 	ft_final_close(commands, fds->i, fds->fd);
// }



void process_commands(t_commande **commands, char ***envp, t_fd *fds)
{
    pid_t pid;
    int fd[2];
    int infile = fds->fd_infile = command_get_fd_infile(commands[0]);
    int outfile;
    int i = 0;

    while (commands[i] != NULL)
    {
       
        if (commands[i + 1] != NULL)
        {
            if (pipe(fd) == -1)
            {
                perror("pipe failed");
                exit(EXIT_FAILURE);
            }
        }
        if (commands[i + 1] == NULL)
            outfile = fds->fd_outfile = command_get_fd_outfile(commands[i]);

        pid = fork();
        if (pid == 0)  
        {
          
            if (i == 0 && infile != STDIN_FILENO)
            {
                dup2(infile, STDIN_FILENO);
                close(infile);
            }

           
            if (i > 0)
            {
                dup2(infile, STDIN_FILENO);
                close(infile);
            }

          
            if (commands[i + 1] != NULL) 
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
            }
            else if (outfile != STDOUT_FILENO)  
            {
                dup2(outfile, STDOUT_FILENO);
                close(outfile);
            }

           
            close(fd[0]);

            
            ft_exec(commands, i, envp);
            perror("exec failed");
            exit(EXIT_FAILURE);
        }
        else if (pid > 0)  
        {
            
            close(fd[1]);
            if (i > 0)
                close(infile);
            infile = fd[0];
        }
        else
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        i++;
    }

  
    close(infile);
}
