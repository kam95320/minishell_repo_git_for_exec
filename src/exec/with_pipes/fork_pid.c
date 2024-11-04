/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:08:28 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/04 15:20:46 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <stdio.h>
#include <stdlib.h>

void	clear_all(t_fd *fds)
{
	if (fds->fd_infile >= 0)
		close(fds->fd_infile);
	if (fds->fd_outfile >= 0)
		close(fds->fd_outfile);
}

int	ft_fork(pid_t pid)
{
	pid = fork();
	if (-1 == pid)
	{
		perror("fork");
		exit(1);
	}
	return (pid);
}

void	ft_pipe(int *fd)
{
	if (-1 == pipe(fd))
	{
		perror("pipe");
		exit(1);
	}
}

void	pipe_fd(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
}
