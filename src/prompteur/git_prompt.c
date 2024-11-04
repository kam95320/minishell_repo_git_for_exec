/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:36:00 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 01:46:31 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../utils/mini_libft/mini_libft.h"
#include "internal.h"
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

static bool	is_git_repo(char *path)
{
	char	*full_path;

	full_path = ft_strjoin(path, "/.git/HEAD");
	if (access(full_path, O_RDONLY | F_OK) == 0)
		return (free(full_path), true);
	return (free(full_path), false);
}

static char	*get_git_branch(char *path)
{
	char	*branch;
	char	*full_path;
	int		fd;
	char	*inf;

	full_path = ft_strjoin(path, "/.git/HEAD");
	if (full_path == NULL)
		return (NULL);
	fd = open(full_path, O_RDONLY);
	free(full_path);
	inf = get_next_line(fd);
	close(fd);
	if (!inf)
		return (NULL);
	branch = ft_substr(inf, ft_strrchr(inf, '/') - inf + 1, ft_strlen(inf));
	free(inf);
	branch[ft_strlen(branch) - 1] = '\0';
	return (branch);
}

static char	*get_project_name(char *path)
{
	char	*project_name;

	project_name = ft_strrchr(path, '/');
	if (project_name == NULL)
		return (NULL);
	return (ft_strdup(project_name + 1));
}

char	*get_path_git_repo(void)
{
	char	*path;
	int		i;

	path = getcwd(NULL, 0);
	i = ft_strlen(path) - 1;
	while (path != NULL && path[0] != '\0')
	{
		if (is_git_repo(path))
		{
			return (path);
		}
		while (path[i] != '/' && path[i] != '\0')
		{
			path[i] = '\0';
			i--;
		}
		if (path[i] == '/')
			path[i] = '\0';
		i--;
	}
	free(path);
	return (NULL);
}

void	append_git_prompt(void *prompt, char *path)
{
	char	*temp;

	append_to_prompt(prompt, "\033[1;34m");
	temp = get_project_name(path);
	append_to_prompt(prompt, temp);
	free(temp);
	append_to_prompt(prompt, "\033[90;30m git(\033[30;92m");
	temp = get_git_branch(path);
	append_to_prompt(prompt, temp);
	free(temp);
	append_to_prompt(prompt, "\033[90;30m)");
	free(path);
	path = NULL;
}
