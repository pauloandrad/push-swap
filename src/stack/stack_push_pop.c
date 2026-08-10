/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:32:27 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/09 19:32:32 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	node_push_top(t_node **top, t_node *new)
{
	if (!top || !new)
		return ;
	new->prev = NULL;
	new->next = *top;
	if (*top)
		(*top)->prev = new;
	*top = new;
}

void	node_push_bottom(t_node **top, t_node *new)
{
	t_node	*tmp;

	if (!top || !new)
		return ;
	if (!*top)
	{
		*top = new;
		return ;
	}
	tmp = (*top);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
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
