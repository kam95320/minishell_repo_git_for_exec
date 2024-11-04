/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:53:59 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 05:55:09 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../mini_libft/mini_libft.h"
#include "internal_checker.h"
#include <aio.h>

t_syntax_error	check_syntax(const char *command_line)
{
	t_syntax_mode	mode;
	t_syntax_error	error;
	size_t			i;

	mode = SM_START_LINE;
	i = 0;
	while (command_line && command_line[i])
	{
		if (is_unexpected_character(command_line[i], mode))
		{
			error = get_syntax_error_from_two_chars(command_line[i],
					command_line[i + 1]);
			if (error != NO_ERROR)
				return (error);
		}
		update_syntax_mode(&mode, command_line[i]);
		i++;
	}
	return (NO_ERROR);
}

void	print_error(t_syntax_error error)
{
	if (error == SE_UNEXPECTED_TOKEN_NEWLINE)
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
			2);
	if (error == SE_UNEXPECTED_TOKEN_DOUBLE_AND)
		ft_putstr_fd("minishell: syntax error near unexpected token `&&'\n", 2);
	if (error == SE_UNEXPECTED_TOKEN_AND)
		ft_putstr_fd("minishell: syntax error near unexpected token `&'\n", 2);
	if (error == SE_UNEXPECTED_TOKEN_DOUBLE_PIPE)
		ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
	if (error == SE_UNEXPECTED_TOKEN_PIPE)
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	if (error == SE_UNEXPECTED_TOKEN_OUTFILE_APPEND)
		ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n", 2);
	if (error == SE_UNEXPECTED_TOKEN_OUTFILE)
		ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
	if (error == SE_UNEXPECTED_TOKEN_INFILE_HEREDOC)
		ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n", 2);
	if (error == SE_UNEXPECTED_TOKEN_INFILE)
		ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 2);
	get_exit_status(2);
}
