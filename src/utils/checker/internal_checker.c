/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:38:02 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/15 14:28:40 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_checker.h"

#define QUOTE 0b1000000
#define SIMPLE_QUOTE 0b100000

unsigned int	get_encode_char(char c)
{
	if (c == '\n')
		return (UN_NEWLINE);
	if (c == '&')
		return (UN_AND);
	if (c == '|')
		return (UN_PIPE);
	if (c == '>')
		return (UN_OUTFILE);
	if (c == '<')
		return (UN_INFILE);
	if (c == '\'')
		return (SIMPLE_QUOTE);
	if (c == '"')
		return (QUOTE);
	return (0);
}

t_syntax_error	get_syntax_error_from_two_chars(char current_char, char next_c)
{
	if (current_char == '\n')
		return (SE_UNEXPECTED_TOKEN_NEWLINE);
	if (current_char == '&' && next_c == '&')
		return (SE_UNEXPECTED_TOKEN_DOUBLE_AND);
	if (current_char == '&')
		return (SE_UNEXPECTED_TOKEN_AND);
	if (current_char == '|' && next_c == '|')
		return (SE_UNEXPECTED_TOKEN_DOUBLE_PIPE);
	if (current_char == '|')
		return (SE_UNEXPECTED_TOKEN_PIPE);
	if (current_char == '>' && next_c == '>')
		return (SE_UNEXPECTED_TOKEN_OUTFILE_APPEND);
	if (current_char == '>')
		return (SE_UNEXPECTED_TOKEN_OUTFILE);
	if (current_char == '<' && next_c == '<')
		return (SE_UNEXPECTED_TOKEN_INFILE_HEREDOC);
	if (current_char == '<')
		return (SE_UNEXPECTED_TOKEN_INFILE);
	return (NO_ERROR);
}

static t_syntax_mode	get_syntax_mode_from_current_char(char current_char)
{
	if (current_char == '\'')
		return (SM_SIMPLE_QUOTE);
	if (current_char == '"')
		return (SM_DOUBLE_QUOTE);
	if (current_char == '|')
		return (SM_SIMPLE_PIPE);
	if (current_char == '&')
		return (SM_SIMPLE_PIPE);
	if (current_char == '>')
		return (SM_SIMPLE_OUTFILE);
	if (current_char == '<')
		return (SM_SIMPLE_INFILE);
	if (current_char == '\'')
		return (SM_SIMPLE_QUOTE);
	if (current_char == '\n')
		return (SM_START_LINE);
	return (SM_STANDARD);
}

void	update_syntax_mode(t_syntax_mode *mode, char current_char)
{
	t_syntax_mode	new_mode;

	if (current_char == ' ')
		new_mode = *mode;
	else
		new_mode = get_syntax_mode_from_current_char(current_char);
	if (new_mode == *mode)
	{
		if (new_mode == SM_SIMPLE_QUOTE || new_mode == SM_DOUBLE_QUOTE)
			*mode = SM_STANDARD;
		if (new_mode == SM_SIMPLE_PIPE)
			*mode = SM_DOUBLE_PIPE;
		if (new_mode == SM_SIMPLE_OUTFILE)
			*mode = SM_DOUBLE_OUTFILE;
		if (new_mode == SM_SIMPLE_INFILE)
			*mode = SM_DOUBLE_INFILE;
	}
	else if (*mode != SM_SIMPLE_QUOTE && *mode != SM_DOUBLE_QUOTE)
		*mode = new_mode;
}

bool	is_unexpected_character(char c, t_syntax_mode mode)
{
	if (mode == SM_SIMPLE_QUOTE || mode == SM_DOUBLE_QUOTE)
		return (false);
	if (c == '\n' && (mode & UN_NEWLINE))
		return (true);
	if (c == '&' && (mode & UN_AND))
		return (true);
	if (c == '|' && (mode & UN_PIPE))
		return (true);
	if (c == '>' && (mode & UN_OUTFILE))
		return (true);
	if (c == '<' && (mode & UN_INFILE))
		return (true);
	return (false);
}
