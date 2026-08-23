/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:54:44 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/23 14:57:54 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	op_sa(t_ps *ps)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	stack_swap_top(&ps->a);
	ps->operations.sa++;
	ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_ps *ps)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	stack_swap_top(&ps->b);
	ps->operations.sb++;
	ft_putstr_fd("sb\n", 1);
}

void	op_pa(t_ps *ps)
{
	t_node	*moved;

	if (!ps || !ps->b)
		return ;
	moved = node_pop_top(&ps->b);
	node_push_top(&ps->a, moved);
	ps->size_a++;
	ps->size_b--;
	ps->operations.pa++;
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_ps *ps)
{
	t_node	*moved;

	if (!ps || !ps->a)
		return ;
	moved = node_pop_top(&ps->a);
	node_push_top(&ps->b, moved);
	ps->size_b++;
	ps->size_a--;
	ps->operations.pb++;
	ft_putstr_fd("pb\n", 1);
}
