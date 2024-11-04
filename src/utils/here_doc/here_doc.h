/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:56:40 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/30 15:21:39 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

/**
 * @brief This function reads from the input until the delimiter found.
 * It writes the input to a pipe and returns the read end of the pipe.
 * @param delimiter The delimiter that will end the reading.
 * @return The fd of the read end of the pipe.
 */
int	heredoc(char *delimiter);

#endif // HERE_DOC_H
