/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:54:44 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/15 14:03:14 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	op_sa(t_ps *ps)
{
	if (!ps || !ps->a.top || !ps->a.top->next)
		return ;
	stack_swap_top(&ps->a.top);
	ps->operations.sa++;
	ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_ps *ps)
{
	if (!ps || !ps->b.top || !ps->b.top->next)
		return ;
	stack_swap_top(&ps->b.top);
	ps->operations.sb++;
	ft_putstr_fd("sb\n", 1);
}

void	op_pa(t_ps *ps)
{
	t_node	*moved;

	if (!ps || !ps->b.top)
		return ;
	moved = node_pop_top(&ps->b.top);
	node_push_top(&ps->a.top, moved);
	ps->a.size++;
	ps->b.size--;
	ps->operations.pa++;
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_ps *ps)
{
	t_node	*moved;

	if (!ps || !ps->a.top)
		return ;
	moved = node_pop_top(&ps->a.top);
	node_push_top(&ps->b.top, moved);
	ps->b.size++;
	ps->a.size--;
	ps->operations.pb++;
	ft_putstr_fd("pb\n", 1);
}
