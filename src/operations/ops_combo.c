/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_combo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:49:19 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/15 14:03:09 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	has_pair(t_node *top)
{
	return (top != NULL && top->next != NULL);
}

void	op_ss(t_ps *ps)
{
	if (!ps || (!has_pair(ps->a.top) && !has_pair(ps->b.top)))
		return ;
	stack_swap_top(&ps->a.top);
	stack_swap_top(&ps->b.top);
	ps->operations.ss++;
	ft_putstr_fd("ss\n", 1);
}

void	op_rr(t_ps *ps)
{
	if (!ps || (!has_pair(ps->a.top) && !has_pair(ps->b.top)))
		return ;
	stack_rotate(&ps->a.top);
	stack_rotate(&ps->b.top);
	ps->operations.rr++;
	ft_putstr_fd("rr\n", 1);
}

void	op_rrr(t_ps *ps)
{
	if (!ps || (!has_pair(ps->a.top) && !has_pair(ps->b.top)))
		return ;
	stack_reverse_rotate(&ps->a.top);
	stack_reverse_rotate(&ps->b.top);
	ps->operations.rrr++;
	ft_putstr_fd("rrr\n", 1);
}
