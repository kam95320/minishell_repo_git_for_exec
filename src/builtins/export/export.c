/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:37:06 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/03 13:57:10 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../structures/commande/commande.h"
#include "export_internal.h"

int	export(t_commande *cmd, char ***g_env)
{
	int	i;

	if (cmd->args[1] == NULL)
	{
		print_sorted_env(*g_env);
		return (0);
	}
	i = 0;
	while (cmd->args[++i])
	{
		if (is_valid_identifier(cmd->args[i]))
			apply_export_for_arg(cmd->args[i], g_env);
		else
			print_invalid_identifier_error(cmd->args[i]);
	}
	return (0);
}
