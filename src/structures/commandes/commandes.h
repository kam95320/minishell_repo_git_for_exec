/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:05:15 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/10 19:20:07 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDES_H
# define COMMANDES_H

# include "../commande/commande.h"
# include "../double_linked_list/double_linked_list.h"
# include <stdbool.h>

typedef t_double_linked_list	t_list_commandes;

/**
 * @brief Create a new list of commandes
 * @return The new list of commandes
 */
t_list_commandes				*list_commandes_create(void);

/**
 * @brief Add a commande to the list of commandes
 * @param commandes The list of commandes
 * @param commande The commande to add
 */
void							list_commandes_add(t_list_commandes *commandes,
									t_commande *commande);

/**
 * @brief Free the list of commandes and its content
 * @param commandes The list of commandes to free
 */
void							list_commandes_free(
									t_list_commandes *commandes);

/**
 * @brief Get the first commande of the list of commandes,
	and remove it from the list
 * @param commandes The list of commandes
 * @return The first commande of the list of commandes
 */
t_commande						*list_commandes_pop(
									t_list_commandes *commandes);

/**
 * @brief Get the first commande of the list of commandes
 * @param commandes The list of commandes
 * @return The first commande of the list of commandes
 */
bool							list_commandes_is_empty(
									t_list_commandes *commandes);

/**
 * @brief Get the number of commandes in the list of commandes
 * @param commandes The list of commandes
 * @return The number of commandes in the list of commandes
 */
unsigned int					list_commandes_get_nb_commandes(
									t_list_commandes *commandes);

/**
 * @brief Convert a list of commandes to an array of commandes,
	the array is NULL terminated
 * @param commandes The list of commandes
 * @return The array of commandes
 */
t_commande						**list_commandes_to_array(
									t_list_commandes *commandes);

#endif // COMMANDES_H
