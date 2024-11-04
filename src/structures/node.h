/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:26:29 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/10 14:45:31 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

//# include <stdio.h>
//# include <unistd.h>

typedef struct node
{
	void		*content;
	struct node	*next;
	struct node	*prev;
}				t_node;

t_node			*node_create(void *content);

#endif // NODE_H
