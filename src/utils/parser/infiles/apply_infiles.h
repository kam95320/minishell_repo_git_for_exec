/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_infiles.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:04:52 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 22:09:41 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_INFILES_H
# define APPLY_INFILES_H

# include "../../../structures/double_linked_list/double_linked_list.h"
# include <stdbool.h>

typedef enum e_infile_type
{
	INFILE_TYPE_FD,
	INFILE_TYPE_STRING
}					t_infile_type;

typedef union u_infile_value
{
	int				fd_value;
	char			*file_name_value;
}					t_infile_value;

typedef struct s_infile
{
	t_infile_type	type;
	t_infile_value	value;
}					t_infile;

t_infile			**extract_infiles(char **command_line);
bool				has_infiles(char **command_line);
bool				has_heredoc(char **command_line);
t_infile			*create_infile_with_filename(char *file_name);
t_infile			*create_infile_with_fd(int fd);
t_infile			**double_linked_list_to_array_infiles(
						t_double_linked_list *list);
void				free_infiles(t_infile **infiles);
void				free_infile(t_infile *infiles);

#endif // APPLY_INFILES_H
