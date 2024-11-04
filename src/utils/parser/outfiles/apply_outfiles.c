/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_outfiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:08:14 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/04 16:19:30 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../internal_parser.h"
#include "apply_outfiles.h"
#include <stdlib.h>

static inline void	move_cell_i_to_last(char **array, int i)
{
	free(array[i]);
	array[i] = array[i + 1];
	while (array[++i])
		array[i] = array[i + 1];
}

t_outfile	**extract_outfiles(char **command_line)
{
	t_double_linked_list	*outfiles;
	t_outfile				*outfile;

	int (i) = 0;
	outfiles = double_linked_list_create();
	while (command_line[i])
	{
		if (equals(command_line[i], ">") || equals(command_line[i], ">>"))
		{
			outfile = malloc(sizeof(t_outfile));
			if (equals(command_line[i], ">>"))
				outfile->type = OUTFILE_TYPE_APPEND;
			else
				outfile->type = OUTFILE_TYPE_REDIR;
			outfile->file_name = apply_strings(command_line[i + 1]);
			double_linked_list_add_last(outfiles, outfile);
			move_cell_i_to_last(command_line, i);
			move_cell_i_to_last(command_line, i);
		}
		else
			i++;
	}
	if (outfiles->size == 0)
		return (free(outfiles), NULL);
	return ((t_outfile **)double_linked_list_to_array(outfiles));
}

bool	has_outfiles(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], ">") || equals(command_line[i], ">>"))
			return (true);
		i++;
	}
	return (false);
}

bool	has_outfiles_append(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], ">>"))
			return (true);
		i++;
	}
	return (false);
}
