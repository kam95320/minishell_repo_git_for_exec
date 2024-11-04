/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:19:23 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/10 19:26:39 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commande/commande.h"
#include "commandes.h"
#include <stdlib.h>

t_list_commandes	*list_commandes_create(void)
{
	t_list_commandes	*new;

	new = malloc(sizeof(t_list_commandes));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return (new);
}

void	list_commandes_add(t_list_commandes *commandes, t_commande *commande)
{
	double_linked_list_add_last(commandes, commande);
}

void	list_commandes_free(t_list_commandes *commandes)
{
	double_linked_list_free(commandes, (void (*)(void *))commande_free);
}

t_commande	*list_commandes_pop(t_list_commandes *commandes)
{
	return (double_linked_list_pop_first(commandes));
}

bool	list_commandes_is_empty(t_list_commandes *commandes)
{
	return (commandes->size == 0);
}
