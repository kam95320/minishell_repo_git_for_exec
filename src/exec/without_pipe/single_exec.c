/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:10:02 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 14:15:36 by kahoumou         ###   ########.fr       */
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
#include "../with_pipes/execution.h"
#include "internal.h"
#include "single_exec.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	execute_single_command(t_commande *command, char ***g_env)
{
	if (command_can_be_executed(command))
	{
		if (is_builtin(command))
			execute_builtins_without_fork(command, g_env);
		else
			execute_external_command(command, g_env);
	}
	else
		get_exit_status(1);
}

bool	is_single_command(t_commande **commands)
{
	return (commands[1] == NULL);
}
