/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:07:12 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/04 15:18:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"
#include "internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	dup_two_infile(int infile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2 failed for infile");
		exit(EXIT_FAILURE);
	}
	close(infile);
}

void	dup_two_outfile(int outfile)
{
	if (outfile < 0)
	{
		perror("Invalid outfile descriptor");
		exit(EXIT_FAILURE);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed for outfile");
		exit(EXIT_FAILURE);
	}
	close(outfile);
}

void	dup_fd_one(int *fd)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed for fd[1]");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
}
