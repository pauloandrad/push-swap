/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:31:09 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/23 15:50:36 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_clear(t_node **top)
{
	t_node	*tmp;
	t_node	*next_cpy;

	if (!top || !*top)
		return ;
	tmp = *top;
	while (tmp != NULL)
	{
		next_cpy = tmp->next;
		free(tmp);
		tmp = next_cpy;
	}
	*top = NULL;
}

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

t_node	*stack_last(t_node *top)
{
	if (!top)
		return (NULL);
	while (top->next != NULL)
		top = top->next;
	return (top);
}
