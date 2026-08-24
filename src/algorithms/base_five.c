/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:00:00 by hegoncal          #+#    #+#             */
/*   Updated: 2026/09/02 20:00:00 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_node *top, int size)
{
	int	min;
	int	pos;
	int	i;

	min = top->rank;
	pos = 0;
	i = 1;
	top = top->next;
	while (i < size)
	{
		if (top->rank < min)
		{
			min = top->rank;
			pos = i;
		}
		top = top->next;
		i++;
	}
	return (pos);
}

static int	find_max_pos(t_node *top, int size)
{
	int	max;
	int	pos;
	int	i;

	max = top->rank;
	pos = 0;
	i = 1;
	top = top->next;
	while (i < size)
	{
		if (top->rank > max)
		{
			max = top->rank;
			pos = i;
		}
		top = top->next;
		i++;
	}
	return (pos);
}

void	base_five_a(t_ps *ps)
{
	int	pos;

	pos = find_min_pos(ps->a, 5);
	if (pos <= 5 - pos)
		while (pos-- > 0)
			op_ra(ps);
	else
		while (pos++ < 5)
			op_rra(ps);
	op_pb(ps);
	pos = find_min_pos(ps->a, 4);
	if (pos <= 4 - pos)
		while (pos-- > 0)
			op_ra(ps);
	else
		while (pos++ < 4)
			op_rra(ps);
	op_pb(ps);
	base_three_a(ps);
	op_pa(ps);
	op_pa(ps);
}

void	base_five_b(t_ps *ps)
{
	int	pos;

	pos = find_max_pos(ps->b, 5);
	if (pos <= 5 - pos)
		while (pos-- > 0)
			op_rb(ps);
	else
		while (pos++ < 5)
			op_rrb(ps);
	op_pa(ps);
	pos = find_max_pos(ps->b, 4);
	if (pos <= 4 - pos)
		while (pos-- > 0)
			op_rb(ps);
	else
		while (pos++ < 4)
			op_rrb(ps);
	op_pa(ps);
	base_three_b(ps);
	op_pb(ps);
	op_pb(ps);
}
