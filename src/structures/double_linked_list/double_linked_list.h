/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:46:38 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 10:15:29 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

# include "double_linked_list_essentials.h"
# include <stdbool.h>

/**
 * @brief Add a content at the head of the linked list
 * @param obj The linked list to add the content
 * @param new_content The content to add
 * @return 0 if the content is added, -1 if malloc failed
 */
int		double_linked_list_add_first(t_double_linked_list *obj,
			void *new_content);

/**
 * @brief Return the first content of the linked list
 * @return The first content of the linked list,
 * or NULL if the linked list is empty
 */
void	*double_linked_list_peak_first(t_double_linked_list *obj);

/**
 * @brief Remove and return the first content of the linked list
 * @return The first content of the linked list,
	or NULL if the linked list is empty
 */
void	*double_linked_list_pop_first(t_double_linked_list *obj);

/**
 * @brief Remove first added element from the double linked list
 * @param obj The double linked list to remove the last element
 * @param free_content The function to free the content of obj,
 * can be NULL if the content is in stack
 */
void	double_linked_list_remove_first(t_double_linked_list *obj,
			void (*free_content)(void *));

/**
 * @brief Add a content at the tail of the linked list
 * @param obj The linked list to add the content
 * @param new_content The content to add
 * @return 0 if the content is added, -1 if malloc failed
 */
int		double_linked_list_add_last(t_double_linked_list *obj,
			void *new_content);

/**
 * @brief Return the last content of the linked list
 * @return The last content of the linked list,
 * or NULL if the linked list is empty
 */
void	*double_linked_list_peak_last(t_double_linked_list *obj);

/**
 * @brief Remove and return the last content of the linked list
 * @return The last content of the linked list,
	or NULL if the linked list is empty
 */
void	*double_linked_list_pop_last(t_double_linked_list *obj);

/**
 * @brief Remove last added element from the double linked list
 * @param obj The double linked list to remove the last element
 * @param free_content The function to free the content of obj,
 * can be NULL if the content is in stack
 */
void	double_linked_list_remove_last(t_double_linked_list *obj,
			void (*free_content)(void *));

/**
 * @brief If the linked list is empty, return false, else return true
 * @return true if the linked list is empty, else false
 */
bool	double_linked_list_has_next(t_double_linked_list *obj);

#endif // DOUBLE_LINKED_LIST_H
