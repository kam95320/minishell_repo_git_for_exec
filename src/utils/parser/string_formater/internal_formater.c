/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_formater.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:49:12 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/12 02:18:04 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_formater.h"

t_string_mode	update_stringmode(char character, t_string_mode string_mode)
{
	if (character == SINGLE_QUOTE || character == DOUBLE_QUOTE)
	{
		if (string_mode == NO_QUOTE)
			return (character);
		else if ((char)string_mode == character)
			return (NO_QUOTE);
	}
	return (string_mode);
}
