/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:35:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/06 16:17:04 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	setup_redirections(int i, t_pipe_info *pipe_info, t_commande **commands)
{
	if (i == 0 && pipe_info->infile != STDIN_FILENO)
	{
		dup2(pipe_info->infile, STDIN_FILENO);
		close(pipe_info->infile);
	}
	if (i > 0)
	{
		dup2(pipe_info->infile, STDIN_FILENO);
		close(pipe_info->infile);
	}
	if (commands[i + 1] != NULL)
	{
		dup2(pipe_info->fd[1], STDOUT_FILENO);
		close(pipe_info->fd[1]);
	}
	else if (pipe_info->outfile != STDOUT_FILENO)
	{
		dup2(pipe_info->outfile, STDOUT_FILENO);
		close(pipe_info->outfile);
	}
	close(pipe_info->fd[0]);
}

void	handle_pipes(int i, t_pipe_info *pipe_info, t_commande **commands)
{
	if (commands[i + 1] != NULL)
	{
		if (pipe(pipe_info->fd) == -1)
		{
			perror("pipe failed");
			exit(EXIT_FAILURE);
		}
	}
}

void	create_and_handle_process(int i, t_pipe_info *pipe_info,
		t_process_data *process_data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		setup_redirections(i, pipe_info, process_data->commands);
		ft_exec(process_data->commands, i, process_data->envp);
		perror("exec failed");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		close(pipe_info->fd[1]);
		if (i > 0)
			close(pipe_info->infile);
		pipe_info->infile = pipe_info->fd[0];
	}
	else
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
}

void	process_commands(t_commande **commands, char ***envp, t_fd *fds)
{
	t_pipe_info		pipe_info;
	t_process_data	process_data;
	int				i;

	process_data.commands = commands;
	process_data.envp = envp;
	process_data.fds = fds;
	fds->fd_infile = command_get_fd_infile(commands[0]);
	pipe_info.infile = fds->fd_infile;
	i = 0;
	while (commands[i] != NULL)
	{
		handle_pipes(i, &pipe_info, commands);
		if (commands[i + 1] == NULL)
		{
			fds->fd_outfile = command_get_fd_outfile(commands[i]);
			pipe_info.outfile = fds->fd_outfile;
		}
		create_and_handle_process(i, &pipe_info, &process_data);
		i++;
	}
	close(pipe_info.infile);
}
