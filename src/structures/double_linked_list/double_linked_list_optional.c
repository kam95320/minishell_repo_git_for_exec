/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_optional.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:16:24 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 10:17:27 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

bool	double_linked_list_has_next(t_double_linked_list *obj)
{
	return (obj->size > 0);
}
