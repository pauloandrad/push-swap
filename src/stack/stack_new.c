/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:31:09 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/08 02:06:21 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*build_stack(int *values, int count)
{
	t_node	*top;
	t_node	*new_node;
	int		i;

	if (!values || count <= 0)
		return (NULL);
	top = NULL;
	i = count - 1;
	while (i >= 0)
	{
		new_node = node_new(values[i]);
		if (!new_node)
		{
			stack_clear(&top);
			return (NULL);
		}
		new_node->next = top;
		if (top)
			top->prev = new_node;
		top = new_node;
		i--;
	}
	return (top);
}

static void	set_op_count(t_op_count *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
}

t_ps	*ps_new(t_node *stack_a)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (NULL);
	ps->a = stack_a;
	ps->b = NULL;
	ps->size_a = stack_size(stack_a);
	ps->size_b = 0;
	ps->disorder = 0.0;
	ps->strategy = ADAPTIVE;
	ps->bench_mode = 0;
	set_op_count(&ps->operations);
	return (ps);
}

void	stack_clear(t_node **top)
{
	t_node	*tmp;
	t_node	*next_cpy;

	if (!top || !*top)
		return ;
	tmp = *top;
	while (tmp != NULL)
	{
		next_cpy = tmp->next;
		free(tmp);
		tmp = next_cpy;
	}
	*top = NULL;
}
