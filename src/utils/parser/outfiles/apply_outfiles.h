/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_outfiles.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:04:52 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 06:21:12 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_OUTFILES_H
# define APPLY_OUTFILES_H

# include <stdbool.h>

typedef enum e_outfile_type
{
	OUTFILE_TYPE_REDIR,
	OUTFILE_TYPE_APPEND
}					t_outfile_type;

typedef struct s_outfile
{
	t_outfile_type	type;
	char			*file_name;
}					t_outfile;

t_outfile			**extract_outfiles(char **command_line);
bool				has_outfiles(char **command_line);

#endif // APPLY_OUTFILES_H
