/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:18:04 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 20:23:28 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../internal_parser.h"
#include "apply_infiles.h"
#include <stdlib.h>

t_infile	*create_infile_with_filename(char *file_name)
{
	t_infile	*infile;

	infile = malloc(sizeof(t_infile));
	if (!infile)
		return (NULL);
	infile->type = INFILE_TYPE_STRING;
	infile->value.file_name_value = apply_strings(file_name);
	return (infile);
}

t_infile	*create_infile_with_fd(int fd)
{
	t_infile	*infile;

	infile = malloc(sizeof(t_infile));
	if (!infile)
		return (NULL);
	infile->type = INFILE_TYPE_FD;
	infile->value.fd_value = fd;
	return (infile);
}

t_infile	**double_linked_list_to_array_infiles(t_double_linked_list *list)
{
	t_infile	**array;
	size_t		i;

	array = malloc(sizeof(t_infile *) * (list->size + 1));
	if (!array)
		return (NULL);
	i = -1;
	while (list->size > 0)
		array[++i] = (t_infile *)double_linked_list_pop_first(list);
	array[++i] = NULL;
	free(list);
	list = NULL;
	return (array);
}

void	free_infile(t_infile *infile)
{
	if (infile->type == INFILE_TYPE_STRING)
	{
		free(infile->value.file_name_value);
		infile->value.file_name_value = NULL;
	}
	free(infile);
	infile = NULL;
}

void	free_infiles(t_infile **infiles)
{
	int	i;

	i = -1;
	while (infiles && infiles[++i])
		free_infile(infiles[i]);
	free(infiles);
	infiles = NULL;
}
