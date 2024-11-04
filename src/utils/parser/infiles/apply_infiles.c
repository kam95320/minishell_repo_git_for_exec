/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_infiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:46:58 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 11:24:36 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../here_doc/here_doc.h"
#include "../internal_parser.h"
#include "apply_infiles.h"
#include <stdlib.h>

static inline void	move_cell_i_to_last(char **array, int i)
{
	free(array[i]);
	array[i] = array[i + 1];
	while (array[++i])
		array[i] = array[i + 1];
}

t_infile	**extract_infiles(char **command_line)
{
	int						i;
	t_double_linked_list	*infiles;

	i = 0;
	infiles = double_linked_list_create();
	while (command_line[i])
	{
		if (equals(command_line[i], "<") || equals(command_line[i], "<<"))
		{
			if (equals(command_line[i], "<<"))
				double_linked_list_add_last(infiles,
					create_infile_with_fd(heredoc(command_line[i + 1])));
			else
				double_linked_list_add_last(infiles,
					create_infile_with_filename(command_line[i + 1]));
			move_cell_i_to_last(command_line, i);
			move_cell_i_to_last(command_line, i);
		}
		else
			i++;
	}
	if (infiles->size == 0)
		return (free(infiles), NULL);
	return (double_linked_list_to_array_infiles(infiles));
}

bool	has_infiles(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], "<"))
			return (true);
		i++;
	}
	return (false);
}

bool	has_heredoc(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], "<<"))
			return (true);
		i++;
	}
	return (false);
}
