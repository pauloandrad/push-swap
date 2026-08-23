/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:49:29 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/23 14:58:44 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	op_ra(t_ps *ps)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	stack_rotate(&ps->a);
	ps->operations.ra++;
	ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_ps *ps)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	stack_rotate(&ps->b);
	ps->operations.rb++;
	ft_putstr_fd("rb\n", 1);
}

void	op_rra(t_ps *ps)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	stack_reverse_rotate(&ps->a);
	ps->operations.rra++;
	ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_ps *ps)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	stack_reverse_rotate(&ps->b);
	ps->operations.rrb++;
	ft_putstr_fd("rrb\n", 1);
}
