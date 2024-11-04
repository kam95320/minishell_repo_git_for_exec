/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:46:57 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/04 15:57:16 by kahoumou         ###   ########.fr       */
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

static void	execute_alll_commands(t_commande **commands, char ***g_env)
{
	int		j;
	t_fd	fds;

	j = command_count(commands);
	process_commands(commands, g_env, &fds);
	while (j > 0)
	{
		waitpid(0, NULL, 0);
		j--;
	}
}

static bool	is_not_empty(const char *str)
{
	if (str && *str && str[0] != '\n' && str[0] != '\0')
	{
		while (*str)
		{
			if (*str != ' ' && *str != '\t')
				return (true);
			str++;
		}
	}
	return (false);
}

static bool	is_a_valid_command_line(const char *command_line)
{
	t_syntax_error	error;

	error = check_syntax(command_line);
	if (error != NO_ERROR)
		return (print_error(error), false);
	return (is_not_empty(command_line));
}

static char	*read_command_line(void)
{
	char	*command_line;
	char	*prompt;

	g_sigint = 0;
	prompt = get_prompt();
	command_line = readline(prompt);
	free(prompt);
	if (command_line == NULL)
	{
		free_env(*get_envp(NULL));
		write(1, "exit\n", 6);
		exit(get_exit_status(_LAST_STATUS));
	}
	return (command_line);
}

int	main(int argc, char const *argv[], char *envp[])
{
	char		*command_line;
	t_commande	**commands;
	char		***g_env;

	arg_is_void_and_signt_init(argc, *argv);
	g_env = get_envp(envp);
	while (1)
	{
		command_line = read_command_line();
		if (is_a_valid_command_line(command_line))
		{
			add_history(command_line);
			commands = parse_command_line(command_line, *g_env);
			if (is_single_command(commands))
				execute_single_command(commands[0], g_env);
			else
			{
				execute_alll_commands(commands, g_env);
				free_commands(commands);
			}
		}
		free(command_line);
	}
	free_env(*g_env);
	return (get_exit_status(_LAST_STATUS));
}
