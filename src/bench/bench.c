/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:20:00 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/20 23:53:22 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_total_ops(t_op_count *ops)
{
	return (ops->sa + ops->sb + ops->ss + ops->pa + ops->pb + ops->ra + ops->rb
		+ ops->rr + ops->rra + ops->rrb + ops->rrr);
}

static void	print_ops_line1(t_op_count *ops, int fd)
{
	ft_putstr_fd("[bench] sa: ", fd);
	ft_putnbr_fd(ops->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(ops->sb, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(ops->ss, fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(ops->pa, fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(ops->pb, fd);
	write(fd, "\n", 1);
}

static void	print_ops_line2(t_op_count *ops, int fd)
{
	ft_putstr_fd("[bench] ra: ", fd);
	ft_putnbr_fd(ops->ra, fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(ops->rb, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(ops->rr, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(ops->rra, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(ops->rrb, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(ops->rrr, fd);
	write(fd, "\n", 1);
}

void	print_bench(t_ps *ps)
{
	int	total;

	total = get_total_ops(&ps->operations);
	print_disorder(ps->disorder, STDERR_FILENO);
	print_strategy(ps->strategy, STDERR_FILENO);
	ft_putstr_fd("[bench] total_ops: ", STDERR_FILENO);
	ft_putnbr_fd(total, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	print_ops_line1(&ps->operations, STDERR_FILENO);
	print_ops_line2(&ps->operations, STDERR_FILENO);
}
