/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:20:13 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 01:45:37 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include <stdbool.h>

char	*get_path_git_repo(void);
void	append_to_prompt(void *prompt, char *str);
void	append_git_prompt(void *prompt, char *path);

#endif // INTERNAL_H
