/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:45:19 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 12:53:45 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIBFT_H
# define MINI_LIBFT_H

# include "../../libft/libft.h"
# include "../../structures/double_linked_list/double_linked_list.h"
# include <aio.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strndup(const char *s, size_t n);
bool	equals(const char *s1, const char *s2);
char	*concatenate(t_double_linked_list *list);
char	*get_word_until(char const *command_line, size_t *i,
			char const delimiter);
char	*get_from_env(char **env, char *word);
char	*ft_get_next_line(int fd);
char	**ft_copy_array(char **array);

#endif // MINI_LIBFT_H
