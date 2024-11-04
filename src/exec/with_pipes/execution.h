/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:11:16 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/04 15:20:11 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "../../structures/commande/commande.h"
# include "../all_executors/executor.h"
# include "../without_pipe/single_exec.h"
# include <sys/types.h>
# include <unistd.h>

void	execute_commands(t_commande **command, char **g_env);
void	process_commands(t_commande **commands, char ***envp, t_fd *fds);
void	exec_cmd(t_commande *commands, char ***g_env);
void	ft_dup_two(t_commande *command, char *in_out, int zero_one, t_fd *fds);
int		ft_fork(pid_t pid);
void	clear_all(t_fd *fds);
void	ft_pid(t_fd *fds);
void	ft_close(t_commande *command, char *fd_in_out, int fd_zero_one,
			t_fd *fds);

#endif // EXECUTION_H
