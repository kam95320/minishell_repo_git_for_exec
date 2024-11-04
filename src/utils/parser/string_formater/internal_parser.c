/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:50:53 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/12 02:18:29 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../structures/double_linked_list/double_linked_list.h"
#include "../internal_parser.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (n + 3));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_word(char const *command_line, size_t *i, char const delimiter)
{
	char	*word;
	char	string_mode;
	size_t	j;

	string_mode = '\0';
	j = *i;
	while (command_line[j] && (string_mode != '\0' || (string_mode == '\0'
				&& command_line[j] != delimiter)))
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

char	**double_linked_list_to_array(t_double_linked_list *list)
{
	char	**result;
	size_t	i;

	result = (char **)malloc(sizeof(char *) * (list->size + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (list->size > 0)
		result[++i] = double_linked_list_pop_first(list);
	result[++i] = NULL;
	free(list);
	list = NULL;
	return (result);
}

char	**split_by_pipe(char const *command_line)
{
	t_double_linked_list	*list;
	size_t					i;

	list = double_linked_list_create();
	if (!list)
		return (NULL);
	i = 0;
	while (command_line[i] && command_line[i] != '\n')
	{
		double_linked_list_add_last(list, get_word(command_line, &i, '|'));
		if (command_line[i] == '\0')
			break ;
		i++;
		if (command_line[i] == '|')
			i++;
	}
	return (double_linked_list_to_array(list));
}
