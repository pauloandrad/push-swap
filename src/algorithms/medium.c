/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:37:43 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/23 14:50:54 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bmax_position(t_ps *ps_b, int index)
{
	int		max_pos;
	t_node	*tmp;

	max_pos = 0;
	tmp = ps_b->b;
	while (tmp)
	{
		if (get_index(ps_b, tmp->value) == index)
			break ;
		max_pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

static void	sort_to_b(t_ps *ps)
{
	int	chunk_size;
	int	limit;
	int	index;

	chunk_size = (ps->size_a * 5 / 100) + 15;
	limit = chunk_size;
	while (ps->a)
	{
		index = get_index(ps, ps->a->value);
		if (index < limit)
		{
			op_pb(ps);
			if (index < limit - (chunk_size / 2))
				op_rb(ps);
			if (stack_size(ps->b) == limit)
				limit += chunk_size;
		}
		else
			op_ra(ps);
	}
}

static void	return_to_a(t_ps *ps)
{
	int	index;
	int	max_pos;

	while (ps->b)
	{
		index = stack_size(ps->b) - 1;
		max_pos = get_bmax_position(ps, index);
		if (max_pos == 0)
			op_pa(ps);
		else if (max_pos <= stack_size(ps->b) / 2)
			op_rb(ps);
		else
			op_rrb(ps);
	}
}

void	run_medium(t_ps *ps)
{
	if (!ps || ps->size_a < 2 || is_sorted(ps->a))
		return ;
	sort_to_b(ps);
	return_to_a(ps);
}
