/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:56:24 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 11:19:06 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef enum e_syntax_error
{
	NO_ERROR,
	SE_UNEXPECTED_TOKEN_NEWLINE,
	SE_UNEXPECTED_TOKEN_SEMICOLON,
	SE_UNEXPECTED_TOKEN_PIPE,
	SE_UNEXPECTED_TOKEN_DOUBLE_PIPE,
	SE_UNEXPECTED_TOKEN_OUTFILE,
	SE_UNEXPECTED_TOKEN_OUTFILE_APPEND,
	SE_UNEXPECTED_TOKEN_INFILE,
	SE_UNEXPECTED_TOKEN_INFILE_HEREDOC,
	SE_UNEXPECTED_TOKEN_AND,
	SE_UNEXPECTED_TOKEN_DOUBLE_AND
}				t_syntax_error;

/**
 * @brief Check the syntax of the command line
 * @param command_line The command line to check
 * @return The syntax error
 */
t_syntax_error	check_syntax(const char *command_line);
void			print_error(t_syntax_error error);

#endif // CHECKER_H
