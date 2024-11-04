/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_essentials.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:02:42 by hsoysal           #+#    #+#             */
/*   Updated: 2024/09/04 15:38:22 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list_essentials.h"
#include <stdlib.h>

t_double_linked_list	*double_linked_list_create(void)
{
	t_double_linked_list	*new;

	new = malloc(sizeof(t_double_linked_list));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return (new);
}

void	double_linked_list_free(t_double_linked_list *obj,
								void (*free_content)(void *))
{
	t_node	*current;
	t_node	*next;

	current = obj->head;
	while (current)
	{
		next = current->next;
		if (free_content)
			free_content(current->content);
		free(current);
		current = NULL;
		current = next;
	}
	free(obj);
	obj = NULL;
}
