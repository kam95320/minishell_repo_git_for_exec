/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:56:13 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 11:12:49 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_INTERNAL_H
# define ECHO_INTERNAL_H

# include <stdbool.h>

bool	has_option_n(char **args);
void	remove_option_from_args(char **args);
void	print_args(char **args);

#endif // ECHO_INTERNAL_H