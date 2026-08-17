/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:52:15 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/16 22:12:16 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

// ToDo: remover;
void	print_stack(t_node *top)
{
	while (top)
	{
		printf("%d\n", top->value);
		top = top->next;
	}
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


