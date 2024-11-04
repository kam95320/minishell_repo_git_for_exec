/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:25:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/04 15:19:38 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"

void	exec_cmd(t_commande *command, char ***g_env)
{
	int	status;

	status = execute_command(command, g_env);
	if (status == -1)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		exit(127);
	}
}

void	ft_exec(t_commande **commands, int i, char ***envp)
{
	exec_cmd(commands[i], envp);
	exit(EXIT_FAILURE);
}
