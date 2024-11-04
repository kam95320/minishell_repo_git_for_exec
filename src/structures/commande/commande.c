/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:26 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/27 15:43:17 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/mini_libft/mini_libft.h"
#include "../../utils/parser/infiles/apply_infiles.h"
#include "../../utils/parser/internal_parser.h"
#include "../../utils/parser/outfiles/apply_outfiles.h"
#include "commande.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

t_commande	*commande_create(char **args)
{
	t_commande	*new_commande;

	new_commande = (t_commande *)malloc(sizeof(t_commande));
	if (new_commande == NULL)
		return (NULL);
	new_commande->infiles = extract_infiles(args);
	new_commande->outfiles = extract_outfiles(args);
	apply_strings_for_args(args);
	new_commande->args = args;
	if (args == NULL || args[0] == NULL)
		new_commande->name = NULL;
	else
		new_commande->name = ft_strdup(args[0]);
	new_commande->path = NULL;
	return (new_commande);
}

bool	commande_has_infile(t_commande *commande)
{
	return (commande->infiles != NULL);
}

bool	commande_has_outfile(t_commande *commande)
{
	return (commande->outfiles != NULL);
}

int	command_get_fd_infile(t_commande *commande)
{
	int	i;

	if (commande->infiles == NULL)
		return (0);
	i = 0;
	while (commande->infiles[i + 1] != NULL)
		i++;
	if (commande->infiles[i]->type == INFILE_TYPE_STRING)
		return (open(commande->infiles[i]->value.file_name_value, O_RDONLY));
	return (commande->infiles[i]->value.fd_value);
}

int	command_get_fd_outfile(t_commande *commande)
{
	int	i;

	if (commande->outfiles == NULL)
		return (1);
	i = 0;
	while (commande->outfiles[i + 1] != NULL)
		i++;
	if (commande->outfiles[i]->type == OUTFILE_TYPE_APPEND)
		return (open(commande->outfiles[i]->file_name,
				O_WRONLY | O_CREAT | O_APPEND, 0644));
	return (open(commande->outfiles[i]->file_name, O_WRONLY | O_CREAT | O_TRUNC,
			0644));
}
