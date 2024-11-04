/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:13:19 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 01:47:38 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _EXIT_SUCCESS 0
# define _EXIT_FAILURE 1
# define _EXIT_ERROR 2
# define _EXIT_NOT_FOUND 127
# define _EXIT_SIGNAL 128
# define _EXIT_QUIT 131
# define _EXIT_INTERRUPT 130
# define _EXIT_PIPE 133
# define _EXIT_EOF 134
# define _EXIT_FORK 135
# define _EXIT_EXECVE 136
# define _LAST_STATUS -2

# define PROMPT "minishell$ "

/**
 * @brief Get the exit status of a process
 * @param status The status of the process,if is -1,
	the function will returnpast status
 */
int		get_exit_status(int status);

char	*get_prompt(void);

#endif // MINISHELL_H
