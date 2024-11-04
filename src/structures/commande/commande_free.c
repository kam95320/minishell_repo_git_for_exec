/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:45:31 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 06:31:13 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commande.h"
#include <stdio.h>
#include <stdlib.h>

static void	free_outfiles(t_outfile **outfiles)
{
	int	i;

	i = -1;
	if (outfiles == NULL)
		return ;
	while (outfiles[++i])
	{
		free(outfiles[i]->file_name);
		outfiles[i]->file_name = NULL;
		free(outfiles[i]);
		outfiles[i] = NULL;
	}
}

static void	free_strings(char **strings)
{
	int	i;

	i = -1;
	if (strings == NULL)
		return ;
	while (strings[++i])
	{
		free(strings[i]);
		strings[i] = NULL;
	}
}

void	commande_free(t_commande *commande)
{
	if (commande == NULL)
		return ;
	free_strings(commande->args);
	free(commande->args);
	commande->args = NULL;
	if (commande->name != NULL)
		free(commande->name);
	commande->name = NULL;
	free_infiles(commande->infiles);
	commande->infiles = NULL;
	free_outfiles(commande->outfiles);
	free(commande->outfiles);
	commande->outfiles = NULL;
	free(commande->path);
	commande->path = NULL;
	free(commande);
	commande = NULL;
}

void	free_commands(t_commande **commands)
{
	int	i;

	i = -1;
	if (commands == NULL)
		return ;
	while (commands[++i])
	{
		commande_free(commands[i]);
		commands[i] = NULL;
	}
	free(commands);
}
