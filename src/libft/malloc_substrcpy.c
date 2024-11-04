/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_substrcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:49:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/22 14:49:32 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloc_substrcpy(char *origin, int start, int end)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = (end - start) + 1;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = origin[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
