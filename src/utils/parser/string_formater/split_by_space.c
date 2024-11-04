/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:43:56 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 01:17:18 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../structures/double_linked_list/double_linked_list.h"
#include "../internal_parser.h"

static bool	is_token(char const *str, const char *token)
{
	return (ft_strncmp(str, token, ft_strlen(token)) == 0);
}

static bool	is_a_token(char const *str)
{
	size_t		i;
	const char	*tokens[] = {">>", "<<", ">", "<"};

	i = 0;
	while (i < sizeof(tokens) / sizeof(tokens[0]))
	{
		if (is_token(str, tokens[i]))
			return (true);
		i++;
	}
	return (false);
}

static char	*get_token(char const *command_line, size_t *i)
{
	size_t	start;

	start = *i;
	if (is_token(command_line + *i, ">>"))
		return ((*i) += 2, ft_substr(command_line, start, 2));
	else if (is_token(command_line + *i, "<<"))
		return ((*i) += 2, ft_substr(command_line, start, 2));
	else if (is_token(command_line + *i, ">"))
		return ((*i) += 1, ft_substr(command_line, start, 1));
	else if (is_token(command_line + *i, "<"))
		return ((*i) += 1, ft_substr(command_line, start, 1));
	return ("");
}

char	*get_word_until_space_or_token(char const *command_line, size_t *i)
{
	char	*word;
	char	string_mode;
	size_t	j;

	string_mode = '\0';
	j = *i;
	while (command_line[j] && (string_mode != '\0' || (string_mode == '\0'
				&& !is_a_token(command_line + j) && command_line[j] != ' ')))
	{
		if (command_line[j] == '\'' || command_line[j] == '\"')
		{
			if (string_mode == '\0')
				string_mode = command_line[j];
			else if (string_mode == command_line[j])
				string_mode = '\0';
		}
		j++;
	}
	word = ft_strndup(command_line + *i, j - *i);
	*i = j;
	return (word);
}

char	**split_by_space(char const *command_line)
{
	t_double_linked_list	*list;
	size_t					i;
	char					*word;

	word = NULL;
	list = double_linked_list_create();
	if (!list)
		return (NULL);
	i = 0;
	while (command_line && command_line[i] != '\0' && command_line[i] != '\n')
	{
		if (is_a_token(command_line + i))
			double_linked_list_add_last(list, get_token(command_line, &i));
		else if (command_line[i] != ' ')
		{
			word = get_word_until_space_or_token(command_line, &i);
			if (word == NULL)
				return (NULL);
			double_linked_list_add_last(list, word);
		}
		else
			i++;
	}
	return (double_linked_list_to_array(list));
}
