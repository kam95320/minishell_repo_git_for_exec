/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_internal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:32:54 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 13:53:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/env/env.h"
#include "export_internal.h"

void	print_sorted_env(char **env)
{
	int		i;
	char	**sorted_env;

	sorted_env = copy_env(env);
	sort_env(sorted_env);
	i = 0;
	while (sorted_env[i])
	{
		printf("declare -x %s\n", sorted_env[i]);
		i++;
	}
	free_env(sorted_env);
}

char	**copy_env(char **env)
{
	int		i;
	int		len;
	char	**copy;

	len = 0;
	while (env[len])
		len++;
	copy = malloc(sizeof(char *) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (env[i])
	{
		copy[i] = strdup(env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	compare_env(const void *a, const void *b)
{
	return (strcmp(*(const char **)a, *(const char **)b));
}

void	sort_env(char **env)
{
	int	len;

	len = 0;
	while (env[len])
		len++;
	qsort(env, len, sizeof(char *), compare_env);
}

void	apply_export_for_arg(char *arg, char ***g_env)
{
	char	*key;
	char	*value;

	if (strchr(arg, '=') != NULL)
	{
		key = strndup(arg, strchr(arg, '=') - arg);
		value = strchr(arg, '=') + 1;
		if (env_contains_var(*g_env, key))
			env_update_var(*g_env, key, value);
		else
			env_add_var(g_env, key, value);
		free(key);
	}
	else
	{
		if (!env_contains_var(*g_env, arg))
			env_add_var(g_env, arg, NULL);
	}
}
