#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;


typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	STRATEGY_COUNT
}	t_strategy;

typedef struct s_op_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_op_count;

typedef struct s_push_swap
{
	t_node		*a;
	t_node		*b;
	int			size_a;
	int			size_b;
	double		disorder;
	t_strategy	strategy;
	int			bench_mode;
	t_op_count	operations;
}	t_push_swap;


typedef void	(*t_fn)(t_push_swap *ps);

int		*parse_args(int argc, char **argv, int *count);
void	check_duplicates(int *values, int count);
void	ps_error(t_push_swap *ps);

t_node	*node_new(int value);
t_node	*build_stack(int *values, int count);
t_ps	*ps_new(t_node *stack_a);
void	stack_clear(t_node **top);
int		stack_size(t_node *top);
int		is_sorted(t_node *top);

void	op_sa(t_push_swap *ps);
void	op_sb(t_push_swap *ps);
void	op_ss(t_push_swap *ps);
void	op_pa(t_push_swap *ps);
void	op_pb(t_push_swap *ps);
void	op_ra(t_push_swap *ps);
void	op_rb(t_push_swap *ps);
void	op_rr(t_push_swap *ps);
void	op_rra(t_push_swap *ps);
void	op_rrb(t_push_swap *ps);
void	op_rrr(t_push_swap *ps);


double	compute_disorder(t_node *top);


void	run_simple(t_push_swap *ps);
void	run_medium(t_push_swap *ps);
void	run_complex(t_push_swap *ps);
void	run_adaptive(t_push_swap);


t_strategy	select_strategy(int argc, char **argv, t_push_swap *ps);
void		dispatch_strategy(t_push_swap *ps);

void	print_bench(t_ps *ps);

#endif
