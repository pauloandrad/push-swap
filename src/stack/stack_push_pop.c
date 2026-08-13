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

void	node_push_front(t_node **top, t_node *node)
{
	if (!top || !node)
		return ;
	node->prev = NULL;
	node->next = *top;
	if (*top)
		(*top)->prev = node;
	*top = node;
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

/* Troca os dois do topo trocando os VALORES, não os nós: nenhum ponteiro
 * precisa ser reatado e o resultado visível na stack é o mesmo. */
void	stack_swap_top(t_node **top)
{
	int	tmp;

	if (!top || !*top || !(*top)->next)
		return ;
	tmp = (*top)->value;
	(*top)->value = (*top)->next->value;
	(*top)->next->value = tmp;
}
