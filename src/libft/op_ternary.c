/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:48 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/02 18:28:09 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	op_ternary(int cond, int cond1, int cond2)
{
	if (cond)
		return (cond1);
	else
		return (cond2);
	return (0);
}
