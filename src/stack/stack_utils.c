/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:52:15 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/23 15:02:48 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_rank(t_node *top, int value)
{
	t_node	*current;
	int		rank;

	rank = 1;
	current = top;
	while (current)
	{
		if (current->value < value)
			rank += 1;
		current = current->next;
	}
	return (rank);
}

void	normalize_stack(t_node *top)
{
	t_node	*current;

	current = top;
	while (current)
	{
		current->rank = find_rank(top, current->value);
		current = current->next;
	}
}
