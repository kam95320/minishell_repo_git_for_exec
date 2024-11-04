/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:16:29 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 05:51:38 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_exit_status(int status)
{
	static int	exit_status = 0;

	if (status != _LAST_STATUS)
		exit_status = status;
	return (exit_status);
}
