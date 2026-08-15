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
	int nodes;
	t_node *tmp;

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

t_node	*find_min(t_node *top)
{
	t_node *min;
	t_node *tmp;

	if (!top)
		return (NULL);
	min = top;
	tmp = top->next;
	while (tmp != NULL)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	find_min_index(t_node *top)
{
	t_node *min;
	int i;

	min = find_min(top);
	if (!min)
		return (-1);
	i = 0;
	while (top != min)
	{
		i++;
		top = top->next;
	}
	return (i);
}

t_node	*stack_last(t_node *top)
{
	if (!top)
		return (NULL);
	while (top->next != NULL)
		top = top->next;
	return (top);
}
