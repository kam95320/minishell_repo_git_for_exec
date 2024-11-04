/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_checker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:54:01 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/18 02:55:21 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_CHECKER_H
# define INTERNAL_CHECKER_H

# include "checker.h"
# include <stdbool.h>
# define UN_NEWLINE 0b00001
# define UN_AND 0b00010
# define UN_INFILE 0b00100
# define UN_OUTFILE 0b01000
# define UN_PIPE 0b10000

typedef enum e_syntax_mode
{
	SM_START_LINE = UN_AND | UN_PIPE,
	SM_SIMPLE_OUTFILE = UN_NEWLINE | UN_INFILE,
	SM_DOUBLE_OUTFILE = SM_SIMPLE_OUTFILE | UN_OUTFILE | UN_PIPE,
	SM_SIMPLE_PIPE = UN_NEWLINE,
	SM_DOUBLE_PIPE = SM_SIMPLE_PIPE | UN_PIPE | UN_AND,
	SM_SIMPLE_INFILE = UN_PIPE | UN_NEWLINE,
	SM_DOUBLE_INFILE = SM_SIMPLE_INFILE | UN_INFILE,
	SM_STANDARD = 0,
	SM_SIMPLE_QUOTE = 0b100000,
	SM_DOUBLE_QUOTE = 0b1000000
}				t_syntax_mode;

void			update_syntax_mode(t_syntax_mode *mode, char current_char);
bool			is_unexpected_character(char c, t_syntax_mode mode);
t_syntax_error	get_syntax_error_from_two_chars(char current_char, char next_c);

#endif // INTERNAL_CHECKER_H
