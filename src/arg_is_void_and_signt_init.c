/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_void_and_signt_init.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:53:57 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/04 15:59:51 by kahoumou         ###   ########.fr       */
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
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

void	arg_is_void_and_signt_init(int argc, char const argv[])
{
	(void)argc;
	(void)argv;
	setup_sigint();
}
