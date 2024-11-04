/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:31:47 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 00:31:59 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/env/env.h"
#include "commande.h"

static char	*add_slash(char *path, char *cmd)
{
	char	*path_part;
	char	*exec;

	path_part = ft_strjoin(path, "/");
	exec = ft_strjoin(path_part, cmd);
	free(path_part);
	return (exec);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*get_path(t_commande *cmd, char **env)
{
	char	*path;
	char	*path_env;
	char	**paths_cmd;
	int		i;

	if (cmd->name == NULL)
		return (NULL);
	path_env = env_get_var(env, "PATH");
	if (path_env == NULL)
		return (ft_strdup(cmd->name));
	paths_cmd = ft_split(path_env, ':');
	i = -1;
	while (paths_cmd[++i])
	{
		path = add_slash(paths_cmd[i], cmd->name);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_split(paths_cmd);
			return (path);
		}
		free(path);
	}
	if (paths_cmd)
		free_split(paths_cmd);
	return (ft_strdup(cmd->name));
}

void	commande_set_path(t_commande *cmd, char **env)
{
	cmd->path = get_path(cmd, env);
}
