/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:40:03 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/15 14:03:30 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	bubble_sort(t_ps *ps)
{
	int	compared;

	compared = 0;
	while (compared < ps->size_a - 1)
	{
		if (ps->a->value > ps->a->next->value)
			op_sa(ps);
		op_ra(ps);
		compared++;
	}
	op_ra(ps);
}

void	run_simple(t_ps *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	while (!is_sorted(ps->a))
		bubble_sort(ps);
}
