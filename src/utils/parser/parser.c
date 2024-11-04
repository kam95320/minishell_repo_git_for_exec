/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:37:33 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/12 06:06:45 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infiles/apply_infiles.h"
#include "internal_parser.h"
#include "outfiles/apply_outfiles.h"
#include "parser.h"
#include <stdlib.h>

static t_double_linked_list	*convert_list_of_args(char *command_line,
		char **env)
{
	char					**commands_brut;
	t_double_linked_list	*commands;
	char					**args;
	int						i;
	t_commande				*commande;

	commands_brut = split_by_pipe(command_line);
	commands = double_linked_list_create();
	i = -1;
	while (commands_brut[++i])
	{
		args = split_by_space(commands_brut[i]);
		apply_dollars_for_args(args, env);
		commande = commande_create(args);
		double_linked_list_add_last(commands, commande);
		free(commands_brut[i]);
		commands_brut[i] = NULL;
	}
	free(commands_brut);
	commands_brut = NULL;
	return (commands);
}

t_commande	**parse_command_line(char *command_line, char **env)
{
	t_double_linked_list	*commands;
	t_commande				**result;
	int						i;

	commands = convert_list_of_args(command_line, env);
	result = (t_commande **)malloc(sizeof(t_commande *) * (commands->size + 1));
	i = -1;
	while (commands->size > 0)
	{
		result[++i] = (t_commande *)double_linked_list_pop_first(commands);
		commande_set_path(result[i], env);
	}
	result[i + 1] = NULL;
	free(commands);
	return (result);
}
