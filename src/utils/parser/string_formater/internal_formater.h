/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_formater.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:46:23 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 06:53:16 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FORMATER_H
# define INTERNAL_FORMATER_H

typedef enum e_string_mode
{
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	NO_QUOTE = '\0'
}				t_string_mode;

t_string_mode	update_stringmode(char character, t_string_mode string_mode);

#endif // INTERNAL_FORMATER_H
