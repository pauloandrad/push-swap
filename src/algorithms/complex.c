/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:38:06 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/22 22:32:33 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_chunk	resolve_chunk(t_ps *ps, t_chunk_strategy chunk, int min, int max)
{
	static t_chunk	chunks[CHUNK_COUNT];
	static int		init;
	t_chunk			chunk_op;

	if (!init)
	{
		chunks[LOW] = (t_chunk){op_pb, op_ra, op_rra, &ps->b, HIGH, 0, 0, 0, 0};
		chunks[HIGH] = (t_chunk){op_pa, op_rb, op_rrb, &ps->a, LOW, 0, 0, 0, 0};
		init = 1;
	}
	chunk_op = chunks[chunk];
	chunk_op.min = min;
	chunk_op.max = max;
	chunk_op.pivot = (min + max) / 2;
	chunk_op.label = chunk;
	return (chunk_op);
}

void	flush_leftover(t_stack *stack, t_ps *ps, t_chunk chunk, int size)
{
	if (size == 1 && stack == &ps->b)
		chunk.op_pd(ps);
	return ;
}
void	sort_a(t_ps *ps, int min, int max, int size)
{
	int	dst_count;
	int	i;

	if (size <= 1)
		return ;
	dst_count = 0;
	i = 0;
	while (i < size)
	{
		if (ps->a->top->rank < (min + max) / 2)
		{
			op_pb(ps);
			dst_count += 1;
		}
	}
}
void	quick_sort(t_stack *src, t_ps *ps, t_chunk chunk, int size)
{
	t_chunk	next_chunk;
	int		dst_count;
	int		i;

	if (size <= 1)
		return (flush_leftover(src, ps, chunk, size));
	dst_count = 0;
	i = 0;
	while (i < size)
	{
		if (src->top->rank < chunk.pivot)
		{
			chunk.op_pd(ps);
			dst_count++;
		}
		else
			chunk.op_rs(ps);
		i++;
	}
	i = 0;
	while (i < size - dst_count)
	{
		chunk.op_rrs(ps);
		i++;
	}
	next_chunk = chunk;
	next_chunk.max = size - dst_count;
	next_chunk.pivot = (chunk.min + next_chunk.max) / 2;
	quick_sort(src, ps, next_chunk, next_chunk.max);
	next_chunk = resolve_chunk(ps, chunk.dest_label, chunk.pivot + 1,
			chunk.max);
	quick_sort(chunk.dest_stack, ps, next_chunk, dst_count);
}

void	run_complex(t_ps *ps)
{
	t_chunk	chunk;

	normalize_stack(ps->a.top);
	chunk = resolve_chunk(ps, HIGH, 1, ps->a.size);
	quick_sort(&ps->a, ps, chunk, ps->a.size);
}
