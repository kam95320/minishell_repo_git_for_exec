/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_exec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:09:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/03 14:06:33 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLE_EXEC_H
# define SINGLE_EXEC_H

# include "../../structures/commande/commande.h"

void	execute_single_command(t_commande *command, char ***g_env);
bool	is_single_command(t_commande **commands);
void	execute_external_command(t_commande *command, char ***g_env);

#endif // SINGLE_EXEC_H
