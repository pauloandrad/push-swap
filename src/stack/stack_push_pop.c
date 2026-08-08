/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:01:08 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/07 22:30:32 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	node_push_front(t_node **top, t_node *new)
{
	if (!top || !new)
		return ;
	new->prev = NULL;
	new->next = *top;
	if (*top)
		(*top)->prev = new;
	*top = new;
}

t_node	*node_pop_front(t_node **top)
{
	t_node	*popped_node;

	if (!top || !*top)
		return (NULL);
	popped_node = *top;
	*top = popped_node->next;
	if (*top)
		(*top)->prev = NULL;
	popped_node->next = NULL;
	popped_node->prev = NULL;
	return (popped_node);
}
