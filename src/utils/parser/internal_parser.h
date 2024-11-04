/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:42:49 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 09:59:42 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_PARSER_H
# define INTERNAL_PARSER_H

# include "../../structures/double_linked_list/double_linked_list.h"
# include "../mini_libft/mini_libft.h"
# include <aio.h>
# include <stdbool.h>

char	**split_by_pipe(char const *command_line);
char	**split_by_space(char const *command_line);
char	**double_linked_list_to_array(t_double_linked_list *list);
char	*get_word(char const *command_line, size_t *i, char const delimiter);
char	*apply_dollars(char *command_line, char **env);
char	*apply_strings(char *str);
void	apply_strings_for_args(char **args);
void	apply_dollars_for_args(char **args, char **env);

#endif // INTERNAL_PARSER_H
