/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_head.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:47:19 by hsoysal           #+#    #+#             */
/*   Updated: 2024/05/03 13:50:39 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"
#include <stdlib.h>

int	double_linked_list_add_first(t_double_linked_list *obj, void *new_content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->content = new_content;
	new->next = obj->head;
	new->prev = NULL;
	if (obj->head)
		obj->head->prev = new;
	obj->head = new;
	if (!obj->tail)
		obj->tail = new;
	obj->size++;
	return (0);
}

void	*double_linked_list_peak_first(t_double_linked_list *obj)
{
	if (obj->head == NULL)
		return (NULL);
	return (obj->head->content);
}

void	*double_linked_list_pop_first(t_double_linked_list *obj)
{
	t_node	*head;
	void	*content;

	if (!obj->head)
		return (NULL);
	head = obj->head;
	obj->head = head->next;
	if (obj->head)
		obj->head->prev = NULL;
	if (head == obj->tail)
		obj->tail = NULL;
	content = head->content;
	free(head);
	obj->size--;
	return (content);
}

void	double_linked_list_remove_first(t_double_linked_list *obj,
		void (*free_content)(void *))
{
	t_node	*head;

	if (obj->head == NULL)
		return ;
	head = obj->head;
	obj->head = head->next;
	if (obj->head != NULL)
		obj->head->prev = NULL;
	if (head == obj->tail)
		obj->tail = NULL;
	if (free_content)
		free_content(head->content);
	free(head);
	obj->size--;
}
