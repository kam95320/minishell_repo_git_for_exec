/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:48:05 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/04 15:39:12 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "executor_internal.h"
#include <stdbool.h>
#include <unistd.h>

bool	command_can_be_executed(t_commande *command)
{
	if (command == NULL || command->name == NULL)
		return (false);
	if (all_infiles_exist(command) && all_outfiles_have_permissions(command))
		return (create_all_outfiles(command), true);
	return (false);
}

// int	execute_command(t_commande *command, char ***g_env)
// {
// 	if (is_builtin(command))
// 		return (execute_builtin(command, g_env));
// 	else
// 		return (execve(command->path, command->args, *g_env));
// 	return (2);
// }

int execute_command(t_commande *command, char ***g_env)
{
    if (is_builtin(command))
        return (execute_builtin(command, g_env));

    // Exécute une commande externe
    if (execve(command->path, command->args, *g_env) == -1)
    {
        perror("execve failed"); // Affiche l'erreur spécifique
        return -1; // Retourne -1 pour indiquer un échec
    }

    return 0; // Ce code ne sera jamais atteint si execve réussit
}


int	execute_command_in_pipe(t_commande *command, char **g_env)
{
	return (execute_command(command, &g_env));
}
