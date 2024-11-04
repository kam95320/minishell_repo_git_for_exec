/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:13:31 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/12 06:55:03 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/mini_libft/mini_libft.h"
#include "env.h"

void	env_update_var(char **envp, char *name, char *value)
{
	char	*var;
	char	*new_var;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) == 0)
		{
			var = ft_strjoin(name, "=");
			new_var = ft_strjoin(var, value);
			free(var);
			free(envp[i]);
			envp[i] = new_var;
			break ;
		}
	}
}

char	*env_get_var(char **envp, char *name)
{
	int		i;
	char	*var;
	char	*value;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) == 0)
		{
			var = ft_strjoin(name, "=");
			value = ft_strchr(envp[i], '=') + 1;
			free(var);
			return (value);
		}
	}
	return (NULL);
}

void	env_add_var(char ***envp, char *name, char *value)
{
	char	**new_envp;
	int		i;

	i = -1;
	while ((*envp)[++i])
		;
	new_envp = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while ((*envp)[++i])
		new_envp[i] = (*envp)[i];
	new_envp[i] = ft_strjoin(name, "=");
	new_envp[i] = ft_strjoin(new_envp[i], value);
	new_envp[i + 1] = NULL;
	free(*envp);
	*envp = new_envp;
}

void	env_remove_var(char ***g_env, char *name)
{
	char	**new_envp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while ((*g_env)[++i])
		if (ft_strncmp((*g_env)[i], name, ft_strlen(name)) != 0)
			j++;
	new_envp = malloc(sizeof(char *) * (j + 1));
	i = -1;
	j = 0;
	while ((*g_env)[++i])
		if (ft_strncmp((*g_env)[i], name, ft_strlen(name)) != 0)
			new_envp[j++] = (*g_env)[i];
	new_envp[j] = NULL;
	free(*g_env);
	*g_env = new_envp;
}

bool	env_contains_var(char **envp, char *name)
{
	return (env_get_var(envp, name) != NULL);
}
