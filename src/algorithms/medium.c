/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hegoncal <hegoncal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:37:43 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/22 15:34:36 by hegoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stack.h"
#include "push_swap.h"
#include <stdio.h>

int	get_bmax_position(t_ps *ps_b, int index)
{
	int		max_pos;
	t_node	*tmp;

	max_pos = 0;
	tmp = ps_b->b;
	while (tmp)
	{
		if (get_index(ps_b, tmp->value) == index)
			break ;
		max_pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

static void	sort_to_b(t_ps *ps)
{
	int	chunk_size;
	int	limit;
	int	index;

	chunk_size = 3;
	limit = chunk_size;
	while (ps->a)
	{
		index = get_index(ps, ps->a->value);
		printf("\n--- Avaliando topo de A (Index: %i | Limite: %i) ---\n",
			index, limit);
		if (index < limit)
		{
			printf("--> [%i < %i] APROVADO! Enviando para B...\n", index,
				limit);
			op_pb(ps);
			if (stack_size(ps->b) == limit)
			{
				limit += chunk_size;
				printf("--> Limite atingido! Próximo limite subiu para %i\n",
					limit);
			}
		}
		else
		{
			printf("--> [%i >= %i] REPROVADO! Rodando A para o final...\n",
				index, limit);
			op_ra(ps);
		}
		printf("Pilha A: ");
		print_stack(ps->a);
		printf("Pilha B: ");
		print_stack(ps->b);
		printf("--------------------------------------------------\n");
	}
}

static void	return_to_a(t_ps *ps)
{
	int	index;
	int	max_pos;

	while (ps->b)
	{
		index = stack_size(ps->b) - 1;
		max_pos = get_bmax_position(ps, index);
		printf("\n--- Procurando o MAIOR (Index: %i) ---\n", index);
		if (max_pos == 0)
		{
			printf("--> ESTÁ NO TOPO! Enviando para A (pa)...\n");
			op_pa(ps);
		}
		else if (max_pos <= stack_size(ps->b) / 2)
		{
			printf("--> Posição %i (CIMA). Rodando B pra cima (rb)...\n",
				max_pos);
			op_rb(ps);
		}
		else
		{
			printf("--> Posição %i (BAIXO). Rodando B pra baixo (rrb)...\n",
				max_pos);
			op_rrb(ps);
		}
		printf("Pilha B: ");
		print_stack(ps->b);
		printf("Pilha A: ");
		print_stack(ps->a);
		printf("--------------------------------------------------\n");
	}
}

void	run_medium(t_ps *ps)
{
	if (!ps || ps->size_a < 2 || is_sorted(ps->a))
		return ;
	sort_to_b(ps);
	return_to_a(ps);
}
