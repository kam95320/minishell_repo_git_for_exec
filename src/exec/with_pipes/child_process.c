/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:23 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/04 15:17:36 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"
#include "internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	child_process(int infile, int outfile, t_commande **commands,
		t_fd *fds)
{
	if (fds -> i > 0)
	{
		dup_two_infile(infile);
	}
	if (commands[fds -> i + 1] != NULL)
	{
		dup_fd_one(fds->fd);
	}
	else
	{
		if (outfile != -1 && outfile != STDOUT_FILENO)
		{
			dup_two_outfile(outfile);
		}
	}
	if (commands[fds -> i + 1] != NULL)
	{
		close(fds-> fd[0]);
	}
}

void	else_if_in_child_process(int *infile, t_commande **commands, int i,
		int *fd)
{
	if (*infile > 0)
	{
		close(*infile);
	}
	if (commands[i + 1] != NULL)
	{
		close(fd[1]);
		*infile = fd[0];
	}
}

void	ft_final_close(t_commande **commands, int i, int *fd)
{
	if (commands[i + 1] != NULL)
	{
		close(fd[0]);
	}
}

void	outfile_fcnlt(int outfile, t_fd *fds)
{
	outfile = fcntl(fds->fd_outfile, F_DUPFD, 10);
	if (outfile == -1)
	{
		perror("dup failed for outfile");
		exit(EXIT_FAILURE);
	}
	close(fds->fd_outfile);
}
