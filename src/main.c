/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:43:28 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/09 20:04:32 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_ps(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->disorder = 0.0;
	ps->strategy = ADAPTIVE;
	ps->bench_mode = 0;
	ps->operations.sa = 0;
	ps->operations.sb = 0;
	ps->operations.ss = 0;
	ps->operations.pa = 0;
	ps->operations.pb = 0;
	ps->operations.ra = 0;
	ps->operations.rb = 0;
	ps->operations.rr = 0;
	ps->operations.rra = 0;
	ps->operations.rrb = 0;
	ps->operations.rrr = 0;
	return (1);
}

void	free_ps(t_ps *ps)
{
	stack_clear(&ps->a);
	stack_clear(&ps->b);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	init_ps(&ps);
	if (!parse_args(argc, argv, &ps))
	{
		free_ps(&ps);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	dispatch_strategy(&ps);
	print_bench(&ps);
	free_ps(&ps);
	return (0);
}

