/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:13:03 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 19:08:44 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdbool.h>

void	env_update_var(char **envp, char *name, char *value);
char	*env_get_var(char **envp, char *name);
void	env_add_var(char ***envp, char *name, char *value);
void	env_remove_var(char ***envp, char *name);
bool	env_contains_var(char **envp, char *name);
char	***get_envp(char **envp);
void	free_env(char **env);

#endif // ENV_H
