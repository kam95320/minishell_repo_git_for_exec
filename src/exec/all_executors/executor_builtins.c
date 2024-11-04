/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:43:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 14:05:26 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins/builtins.h"
#include "../../utils/mini_libft/mini_libft.h"
#include "executor_internal.h"

bool	is_builtin(t_commande *command)
{
	if (equals(command->name, "echo"))
		return (true);
	if (equals(command->name, "cd"))
		return (true);
	if (equals(command->name, "export"))
		return (true);
	if (equals(command->name, "unset"))
		return (true);
	if (equals(command->name, "env"))
		return (true);
	if (equals(command->name, "exit"))
		return (true);
	if (equals(command->name, "pwd"))
		return (true);
	return (false);
}

int	execute_builtin(t_commande *command, char ***g_env)
{
	if (equals(command->name, "echo"))
		return (echo(command));
	else if (equals(command->name, "cd"))
		return (cd(command, *g_env));
	else if (equals(command->name, "export"))
		return (export(command, g_env));
	else if (equals(command->name, "unset"))
		return (unset(command, g_env));
	else if (equals(command->name, "env"))
		return (env(command, *g_env));
	else if (equals(command->name, "pwd"))
		return (pwd(command));
	else if (equals(command->name, "exit"))
		return (bultin_exit(command));
	return (0);
}
