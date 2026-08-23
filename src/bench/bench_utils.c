/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:20:00 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/20 23:53:14 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(float disorder, int fd)
{
	int		integer_part;
	int		decimal_part;
	float	pct;

	pct = disorder * 100;
	integer_part = (int)pct;
	decimal_part = (int)((pct - integer_part) * 100 + 0.5f);
	if (decimal_part >= 100)
	{
		integer_part++;
		decimal_part = 0;
	}
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(integer_part, fd);
	write(fd, ".", 1);
	if (decimal_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal_part, fd);
	ft_putstr_fd("%\n", fd);
}

void	print_strategy(t_strategy strategy, int fd)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	if (strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n²)\n", fd);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", fd);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", fd);
	else if (strategy == ADAPTIVE)
		ft_putstr_fd("Adaptive / O(n√n)\n", fd);
}
