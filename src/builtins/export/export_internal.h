/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:18 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 13:57:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_INTERNAL_H
# define EXPORT_INTERNAL_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

bool	is_valid_identifier(char *arg);
void	apply_export_for_arg(char *arg, char ***g_env);
void	print_sorted_env(char **env);
void	print_invalid_identifier_error(char *arg);
bool	env_contains_var(char **env, char *key);
void	env_update_var(char **env, char *key, char *value);
void	env_add_var(char ***env, char *key, char *value);
char	**copy_env(char **env);
void	sort_env(char **env);
void	free_env(char **env);

#endif // EXPORT_INTERNAL_H
