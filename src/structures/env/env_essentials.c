/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_essentials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:07:54 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 19:35:50 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "env.h"
#include <stdlib.h>

void	free_env(char **env)
{
	int	i;

	i = -1;
	if (env == NULL)
	{
		if (get_envp(NULL) != NULL)
		{
			free_env(*get_envp(NULL));
			*get_envp(NULL) = NULL;
		}
		return ;
	}
	while (env[++i])
	{
		free(env[i]);
		env[i] = NULL;
	}
	free(env);
	env = NULL;
}

static char	**copy_envp(char **envp)
{
	int		i;
	char	**new_envp;

	i = -1;
	while (envp[++i])
		;
	new_envp = malloc(sizeof(char *) * (i + 1));
	if (!new_envp)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		new_envp[i] = ft_strdup(envp[i]);
	}
	new_envp[i] = NULL;
	return (new_envp);
}

char	***get_envp(char **envp)
{
	static char	**envp_static;

	if (envp)
		envp_static = copy_envp(envp);
	return (&envp_static);
}
