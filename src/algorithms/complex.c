/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:38:06 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/16 22:42:06 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_chunk_op	select_chunk_ops(t_ps *ps, t_chunk_strategy chunk)
{
	static t_chunk_op	chunk_ops[CHUNK_COUNT];
	static int			init;

	if (!init)
	{
		chunk_ops[LOW] = (t_chunk_op){op_pb, op_ra, &ps->b, HIGH};
		chunk_ops[HIGH] = (t_chunk_op){op_pa, op_rb, &ps->a, LOW};
		init = 1;
	}
	return (chunk_ops[chunk]);
}

void	quick_sort(t_stack *stack, t_ps *ps, t_chunk_strategy chunk, int size)
{
	t_chunk_op	chunk_ops;
	int			pivot;
	int			dst_count;
	int			i;

	if (size <= 1)
		return ;
	chunk_ops = select_chunk_ops(ps, chunk);
	pivot = stack->top->value;
	dst_count = 0;
	i = 0;
	while (i < size)
	{
		if (stack->top->value < pivot)
		{
			chunk_ops.op_pd(ps);
			dst_count++;
		}
		else
			chunk_ops.op_rs(ps);
		i++;
	}
	quick_sort(chunk_ops.other, ps, chunk_ops.other_chunk, dst_count);
	quick_sort(stack, ps, chunk, size - dst_count);
}

void	run_complex(t_ps *ps)
{
	quick_sort(&ps->a, ps, LOW, ps->a.size);
}
