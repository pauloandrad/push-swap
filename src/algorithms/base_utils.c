/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:00:00 by hegoncal          #+#    #+#             */
/*   Updated: 2026/09/02 20:00:00 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_base_b(t_ps *ps, int size)
{
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		if (ps->b->rank < ps->b->next->rank)
			op_sb(ps);
		return (1);
	}
	if (size == 3 && ps->size_b == 3)
	{
		base_three_b(ps);
		return (1);
	}
	if (size == 5 && ps->size_b == 5)
	{
		base_five_b(ps);
		return (1);
	}
	return (0);
}

int	handle_base_a(t_ps *ps, int size)
{
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		if (ps->a->rank > ps->a->next->rank)
			op_sa(ps);
		return (1);
	}
	if (size == 3 && ps->size_a == 3)
	{
		base_three_a(ps);
		return (1);
	}
	if (size == 5 && ps->size_a == 5)
	{
		base_five_a(ps);
		return (1);
	}
	return (0);
}
