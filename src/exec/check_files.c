/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:57:30 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/04 12:57:31 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "all_executors/executor_internal.h"
#include <unistd.h>

bool	is_a_directory(char *file_name)
{
	return (access(file_name, F_OK) == 0 && access(file_name, X_OK) == 0);
}

bool	all_infiles_exist(t_commande *command)
{
	int			i;
	t_infile	*infile;

	i = 0;
	if (command->infiles == NULL)
		return (true);
	while (command->infiles[i])
	{
		infile = command->infiles[i];
		if (infile->type == INFILE_TYPE_STRING
			&& access(infile->value.file_name_value, F_OK) == -1)
		{
			no_such_file_or_directory(infile);
		}
		if (infile->type == INFILE_TYPE_STRING
			&& access(infile->value.file_name_value, F_OK) == 0
			&& access(infile->value.file_name_value, R_OK) == -1)
		{
			permisson_denied(infile);
		}
		i++;
	}
	return (true);
}

bool	all_outfiles_have_permissions(t_commande *command)
{
	int	i;

	i = 0;
	if (command->outfiles == NULL)
		return (true);
	while (command->outfiles[i])
	{
		if (access(command->outfiles[i]->file_name, F_OK) != -1
			&& access(command->outfiles[i]->file_name, W_OK) == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(command->outfiles[i]->file_name, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

void	create_all_outfiles(t_commande *command)
{
	int	i;

	i = 0;
	if (command->outfiles == NULL)
		return ;
	while (command->outfiles[i])
	{
		if (access(command->outfiles[i]->file_name, F_OK) == -1)
		{
			if (command->outfiles[i]->type == OUTFILE_TYPE_APPEND)
				open(command->outfiles[i]->file_name,
					O_CREAT | O_WRONLY | O_APPEND,
					0644);
			else
				open(command->outfiles[i]->file_name,
					O_CREAT | O_WRONLY | O_TRUNC,
					0644);
		}
		i++;
	}
}
