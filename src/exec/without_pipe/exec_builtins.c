/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:09:10 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 14:07:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../../utils/checker/checker.h"
#include "../../utils/mini_libft/mini_libft.h"
#include "../../utils/parser/parser.h"
#include "../all_executors/executor.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	execute_builtins_without_fork(t_commande *command, char ***g_env)
{
	int	fd_in;
	int	fd_out;
	int	original_stdout;
	int	original_stdin;

	original_stdout = dup(1);
	original_stdin = dup(0);
	fd_in = command_get_fd_infile(command);
	fd_out = command_get_fd_outfile(command);
	if (fd_in != 0)
		dup2(fd_in, 0);
	if (fd_out != 1)
		dup2(fd_out, 1);
	get_exit_status(execute_builtin(command, g_env));
	if (fd_in != 0)
		close(fd_in);
	if (fd_out != 1)
		close(fd_out);
	dup2(original_stdout, 1);
	dup2(original_stdin, 0);
	close(original_stdout);
	close(original_stdin);
}
