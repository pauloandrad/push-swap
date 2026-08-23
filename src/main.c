/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:43:28 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/23 15:33:45 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "stdio.h"

void	print_stack2(t_node *top)
{
	t_node *tmp;

	tmp = top;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

void	free_ps(t_ps *ps)
{
	stack_clear(&ps->a);
	stack_clear(&ps->b);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	ps = (t_ps){0};
	ps.strategy = ADAPTIVE;
	if (!parse_args(argc, argv, &ps))
	{
		free_ps(&ps);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	dispatch_strategy(&ps);
	if (ps.bench_mode)
		print_bench(&ps);
	free_ps(&ps);
	return (0);
}
