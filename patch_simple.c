#include "push_swap.h"

static int	get_min_pos(t_node *top)
{
	int	min;
	int	pos;
	int	i;

	if (!top)
		return (0);
	min = top->rank;
	pos = 0;
	i = 1;
	top = top->next;
	while (top)
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

void	run_simple(t_ps *ps)
{
	int	pos;
	int	rra_count;

	if (!ps || ps->size_a < 2 || is_sorted(ps->a))
		return ;
	normalize_stack(ps->a);
	while (ps->size_a > 3)
	{
		pos = get_min_pos(ps->a);
		if (pos <= ps->size_a / 2)
			while (pos-- > 0)
				op_ra(ps);
		else
		{
			rra_count = ps->size_a - pos;
			while (rra_count-- > 0)
				op_rra(ps);
		}
		op_pb(ps);
	}
	if (ps->size_a == 3)
		base_three_a(ps);
	else if (ps->size_a == 2 && ps->a->rank > ps->a->next->rank)
		op_sa(ps);
	while (ps->size_b > 0)
		op_pa(ps);
}
