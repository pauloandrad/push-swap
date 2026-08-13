/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:30:12 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/10 21:34:51 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*stack_last(t_node *top)
{
	if (!top)
		return (NULL);
	while (top->next != NULL)
		top = top->next;
	return (top);
}

void	stack_rotate(t_node **top)
{
	t_node	*first;
	t_node	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	first = node_pop_front(top);
	last = stack_last(*top);
	last->next = first;
	first->prev = last;
}

void	stack_reverse_rotate(t_node **top)
{
	t_node	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	last = stack_last(*top);
	last->prev->next = NULL;
	last->prev = NULL;
	node_push_front(top, last);
}
