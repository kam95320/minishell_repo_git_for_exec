/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:42:44 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/04 16:00:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/all_executors/executor.h"
#include "exec/with_pipes/execution.h"
#include "exec/without_pipe/single_exec.h"
#include "minishell.h"
#include "signals/sigint/sigint.h"
#include "structures/commande/commande.h"
#include "structures/env/env.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	command_count(t_commande **commands)
{
	int	i;

	i = 0;
	while (commands[i] != 0)
	{
		i++;
	}
	return (i);
}
