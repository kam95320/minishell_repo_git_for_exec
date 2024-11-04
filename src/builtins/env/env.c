/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:00:18 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/12 02:16:42 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/mini_libft/mini_libft.h"
#include "../builtins.h"

int	env(t_commande *cmd, char **envp)
{
	int	i;

	i = -1;
	(void)cmd;
	while (envp[++i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
