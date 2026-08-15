/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:30:12 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/12 23:48:15 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_rotate(t_node **top)
{
	t_node	*first;
	t_node	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	first = node_pop_top(top);
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
	node_push_top(top, last);
}
