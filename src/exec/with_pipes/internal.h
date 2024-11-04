/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:40:23 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/04 15:21:44 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "execution.h"

int		ft_fork(pid_t pid);
void	ft_pipe(int *fd);
void	dup_two_infile(int infile);
void	dup_two_outfile(int outfile);
void	dup_fd_one(int *fd);
void	pipe_fd(int *fd);
void	ft_exec(t_commande **commands, int i, char ***envp);
void	child_process(int infile, int outfile, t_commande **commands,
			t_fd *fds);
void	else_if_in_child_process(int *infile, t_commande **commands, int i,
			int *fd);
void	ft_final_close(t_commande **commands, int i, int *fd);
void	outfile_fcnlt(int outfile, t_fd *fds);
int		take_nb(int i);
#endif // INTERNAL_H
