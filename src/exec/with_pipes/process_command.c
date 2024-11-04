/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:35:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/04 15:31:27 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"
#include "internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ft_perror_fork(void)
{
	perror("fork failed");
	exit(EXIT_FAILURE);
}

void	process_commands(t_commande **commands, char ***envp, t_fd *fds)
{
	pid_t	pid;

	fds->i = 0;
	fds->fd_infile = command_get_fd_infile(commands[fds->i]);
	while (commands[fds->i] != NULL)
	{
		if (commands[fds->i + 1] != NULL)
			pipe_fd(fds->fd);
		if (commands[fds->i + 1] == NULL)
			fds->fd_outfile = command_get_fd_outfile(commands[fds->i]);
		pid = fork();
		if (pid == 0)
		{
			child_process(fds->fd_infile, fds->fd_outfile, commands, fds);
			ft_exec(commands, fds->i, envp);
		}
		else if (pid > 0)
			else_if_in_child_process(&fds->fd_infile, commands, fds->i,
				fds->fd);
		else
			ft_perror_fork();
		fds->i++;
	}
	ft_final_close(commands, fds->i, fds->fd);
}
