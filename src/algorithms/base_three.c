
#include "push_swap.h"

void	base_three_a(t_ps *ps)
{
	int	max;

	max = ps->a->rank;
	if (ps->a->next->rank > max)
		max = ps->a->next->rank;
	if (ps->a->next->next->rank > max)
		max = ps->a->next->next->rank;
	if (ps->a->rank == max)
		op_ra(ps);
	else if (ps->a->next->rank == max)
		op_rra(ps);
	if (ps->a->rank > ps->a->next->rank)
		op_sa(ps);
}

void	base_three_b(t_ps *ps)
{
	int	min;

	min = ps->b->rank;
	if (ps->b->next->rank < min)
		min = ps->b->next->rank;
	if (ps->b->next->next->rank < min)
		min = ps->b->next->next->rank;
	if (ps->b->rank == min)
		op_rb(ps);
	else if (ps->b->next->rank == min)
		op_rrb(ps);
	if (ps->b->rank < ps->b->next->rank)
		op_sb(ps);
}