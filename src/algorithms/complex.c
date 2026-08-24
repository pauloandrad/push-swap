/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:38:06 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/23 20:18:26 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_a(t_ps *ps, int min, int max, int size);

int	sort_b(t_ps *ps, int size, int pivot)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < size)
	{
		if (ps->b->rank >= pivot)
		{
			op_pa(ps);
			pushed += 1;
		}
		else
			op_rb(ps);
		i++;
	}
	i = 0;
	while (i < size - pushed)
	{
		op_rrb(ps);
		i++;
	}
	return (pushed);
}

void	quick_sort_b(t_ps *ps, int min, int max, int size)
{
	int	pushed;
	int	pivot;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (ps->b->rank < ps->b->next->rank)
			op_sb(ps);
		return ;
	}
	if (size == 3)
	{
		base_three_b(ps);
		return ;
	}
	if (size == 5)
	{
		base_five_b(ps);
		return ;
	}
	pivot = (min + max + 1) / 2;
	pushed = sort_b(ps, size, pivot);
	quick_sort_b(ps, min, pivot - 1, size - pushed);
	quick_sort_a(ps, pivot, max, pushed);
	while (pushed-- > 0)
		op_pb(ps);
}

int	sort_a(t_ps *ps, int size, int pivot)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < size)
	{
		if (ps->a->rank < pivot)
		{
			op_pb(ps);
			pushed += 1;
		}
		else
			op_ra(ps);
		i++;
	}
	i = 0;
	while (i < size - pushed)
	{
		op_rra(ps);
		i++;
	}
	return (pushed);
}

void	quick_sort_a(t_ps *ps, int min, int max, int size)
{
	int	pushed;
	int	pivot;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (ps->a->rank > ps->a->next->rank)
			op_sa(ps);
		return ;
	}
	if (size == 3)
	{
		base_three_a(ps);
		return ;
	}
	if (size == 5)
	{
		base_five_a(ps);
		return ;
	}
	pivot = (min + max + 1) / 2;
	pushed = sort_a(ps, size, pivot);
	quick_sort_a(ps, pivot, max, size - pushed);
	quick_sort_b(ps, min, pivot - 1, pushed);
	while (pushed-- > 0)
		op_pa(ps);
}

void	run_complex(t_ps *ps)
{
	normalize_stack(ps->a);
	quick_sort_a(ps, 1, ps->size_a, ps->size_a);
}
