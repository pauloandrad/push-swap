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

/* =============================================================================
 * stack_push_pop.c
 *
 * O QUE FAZER AQUI:
 * - Funções de baixo nível para manipular a lista duplamente ligada que
 *   representa cada stack (independente das operações sa/pa/ra do subject,
 *   que ficam em operations/):
 *     - node_push_front(t_node **top, t_node *node)
 *     - t_node *node_pop_front(t_node **top)
 * - Essas funções são os "tijolos" usados por operations/ops_single.c para
 *   implementar sa, sb, pa, pb, ra, rb, rra, rrb.
 * - Cuidado com os ponteiros prev/next se a lista for circular ou dupla,
 *   para as rotações (ra/rra) ficarem O(1).
 * ========================================================================== */

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
