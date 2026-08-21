/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/08/07 21:36:19 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/08 01:15:35 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_node *top)
{
	int		nodes;
	t_node	*tmp;

	nodes = 0;
	tmp = top;
	while (tmp != NULL)
	{
		nodes++;
		tmp = tmp->next;
	}
	return (nodes);
}

int	is_sorted(t_node *top)
{
	if (!top)
		return (1);
	while (top->next != NULL)
	{
		if (top->value > top->next->value)
			return (0);
		top = top->next;
	}
	return (1);
}

int	get_index(t_ps *ps, int current_value)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = ps->a;
	while (tmp)
	{
		if (tmp->value < current_value)
			index++;
		tmp = tmp->next;
	}
	tmp = ps->b;
	while (tmp)
	{
		if (tmp->value < current_value)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

t_node	*stack_last(t_node *top)
{
	if (!top)
		return (NULL);
	while (top->next != NULL)
		top = top->next;
	return (top);
}
