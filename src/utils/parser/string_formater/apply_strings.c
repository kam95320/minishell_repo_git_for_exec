/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 05:26:30 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 11:03:22 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../internal_parser.h"
#include <stdlib.h>

void	apply_strings_for_args(char **args)
{
	int		i;
	char	*temp;

	i = -1;
	while (args[++i])
	{
		temp = args[i];
		args[i] = apply_strings(args[i]);
		free(temp);
		temp = NULL;
	}
}

char	*apply_strings(char *str)
{
	int		i_src;
	int		i_dest;
	char	string_mode;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	string_mode = '\0';
	i_dest = -1;
	i_src = -1;
	while (str[++i_src])
	{
		if ((str[i_src] == '\'' || str[i_src] == '\"') && string_mode == '\0')
			string_mode = str[i_src];
		else if (string_mode == str[i_src])
			string_mode = '\0';
		else
			new_str[++i_dest] = str[i_src];
	}
	new_str[++i_dest] = '\0';
	return (new_str);
}
