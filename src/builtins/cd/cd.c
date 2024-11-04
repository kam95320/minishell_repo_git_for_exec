/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/10 19:04:47 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	cd(t_commande *cmd, char **envp)
{
	char	*pwd;

	if (!cmd->args[1])
		return (0);
	if (chdir(cmd->args[1]) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (2);
	}
	pwd = getcwd(NULL, 0);
	env_update_var(envp, "PWD", pwd);
	free(pwd);
	return (0);
}
