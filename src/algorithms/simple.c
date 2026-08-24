/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:40:03 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/23 15:50:36 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(t_ps *ps)
{
	int	sorted;
	int	i;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < ps->size_a - 1)
		{
			if (ps->a->rank > ps->a->next->rank)
			{
				op_sa(ps);
				sorted = 0;
			}
			op_ra(ps);
			i++;
		}
		op_ra(ps);
	}
}

void	run_simple(t_ps *ps)
{
	if (!ps || ps->size_a < 2 || is_sorted(ps->a))
		return ;
	normalize_stack(ps->a);
	if (ps->size_a == 3)
	{
		base_three_a(ps);
		return ;
	}
	if (ps->size_a == 5)
	{
		base_five_a(ps);
		return ;
	}
	bubble_sort(ps);
}
