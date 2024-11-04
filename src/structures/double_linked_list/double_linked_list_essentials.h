/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_essentials.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:57:24 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/15 21:49:24 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_ESSENTIALS_H
# define DOUBLE_LINKED_LIST_ESSENTIALS_H

# include "../node.h"

/**
 * @brief The structure of a double linked list
 */
typedef struct double_linked_list
{
	t_node				*head;
	t_node				*tail;
	unsigned int		size;
}						t_double_linked_list;

/**
 * @brief Create a new linked list, the linked list is LIFO (Last In First Out)
 * @return The new linked list
 */
t_double_linked_list	*double_linked_list_create(void);

/**
 * @brief Free the linked list and its content
 * @param obj The linked list to free
 * @param free_content The function to free the content of the linked list,
	can be NULL if the content is in stack
 */
void					double_linked_list_free(t_double_linked_list *obj,
							void (*free_content)(void *));

#endif // DOUBLE_LINKED_LIST_ESSENTIALS_H
