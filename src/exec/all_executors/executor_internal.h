/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:30:55 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/04 13:18:13 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_INTERNAL_H
# define EXECUTOR_INTERNAL_H

# include "../../structures/commande/commande.h"
# include <stdbool.h>

bool	all_infiles_exist(t_commande *command);
bool	all_outfiles_have_permissions(t_commande *command);
void	create_all_outfiles(t_commande *command);
bool	permisson_denied(t_infile *infile);
bool	no_such_file_or_directory(t_infile *infile);

#endif // EXECUTOR_INTERNAL_H
