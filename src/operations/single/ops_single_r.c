/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_single_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:49:29 by hegoncal          #+#    #+#             */
/*   Updated: 2026/08/10 21:35:02 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============================================================================
 * ops_single_r.c — as quatro rotações simples (ra, rb, rra, rrb)
 *
 * Toda a mecânica de ponteiros mora em stack/stack_rotate.c. Aqui cada
 * função só faz três coisas, sempre na mesma ordem:
 *   1. sai fora se a stack tem menos de 2 nós (rotacionar não mudaria nada)
 *   2. rotaciona
 *   3. conta a operação e imprime o nome dela em stdout
 * ========================================================================== */

#include "../../../includes/push_swap.h"

void	op_ra(t_ps *ps)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	stack_rotate(&ps->a);
	ps->operations.ra++;
	ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_ps *ps)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	stack_rotate(&ps->b);
	ps->operations.rb++;
	ft_putstr_fd("rb\n", 1);
}

void	op_rra(t_ps *ps)
{
	if (!ps || !ps->a || !ps->a->next)
		return ;
	stack_reverse_rotate(&ps->a);
	ps->operations.rra++;
	ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_ps *ps)
{
	if (!ps || !ps->b || !ps->b->next)
		return ;
	stack_reverse_rotate(&ps->b);
	ps->operations.rrb++;
	ft_putstr_fd("rrb\n", 1);
}
