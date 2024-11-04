/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_dollars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:18:36 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/12 02:17:45 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"
#include "../../../structures/double_linked_list/double_linked_list.h"
#include "../internal_parser.h"
#include "internal_formater.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_valid_dollar(char c)
{
	return (c == '_' || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

static char	*get_dollar(char const *command_line, size_t *i, t_string_mode mode,
		char **env)
{
	size_t	j;
	char	*result;

	(*i)++;
	j = *i;
	(void)mode;
	if (command_line[j] == '?')
	{
		(*i)++;
		return (ft_itoa(get_exit_status(_LAST_STATUS)));
	}
	if (!is_valid_dollar(command_line[j]))
		return (ft_strndup("$", 1));
	while (command_line[j] && is_valid_dollar(command_line[j]))
		j++;
	result = get_from_env(env, ft_strndup(command_line + *i, j - *i));
	*i = j;
	return (result);
}

void	apply_dollars_for_args(char **args, char **env)
{
	int	i;

	i = -1;
	while (args[++i])
		args[i] = apply_dollars(args[i], env);
}

char	*get_word_until_two_chars(char const *command_line, size_t *i,
		char delimiter)
{
	char	*word;
	size_t	j;

	j = *i;
	j++;
	while (command_line[j] && command_line[j] != delimiter
		&& command_line[j] != '$')
		j++;
	word = ft_strndup(command_line + *i, j - *i);
	*i = j;
	return (word);
}

char	*apply_dollars(char *command_line, char **env)
{
	t_double_linked_list	*list;
	size_t					i;
	char					*result;
	t_string_mode			string_mode;

	string_mode = NO_QUOTE;
	list = double_linked_list_create();
	i = 0;
	while (command_line[i])
	{
		string_mode = update_stringmode(command_line[i], string_mode);
		if (command_line[i] == '$' && string_mode != SINGLE_QUOTE)
			double_linked_list_add_last(list, get_dollar(command_line, &i,
					string_mode, env));
		else
			double_linked_list_add_last(list,
				get_word_until_two_chars(command_line, &i, string_mode));
	}
	result = concatenate(list);
	free(command_line);
	return (result);
}
