/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:02:06 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/23 14:53:57 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

float	calculate_disorder(t_node *top)
{
	float	errs;
	float	total_pairs;
	t_node	*i;
	t_node	*j;

	if (stack_size(top) <= 1)
		return (0);
	errs = 0;
	total_pairs = 0;
	i = top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs += 1;
			if (i->value > j->value)
				errs += 1;
			j = j->next;
		}
		i = i->next;
	}
	return (errs / total_pairs);
}

void	(*select_strategy(t_ps *ps))(t_ps *ps)
{
	if (ps->disorder < 0.2)
	{
		ps->adap_strategy = SIMPLE;
		return (run_simple);
	}
	else if (ps->disorder >= 0.2 && ps->disorder < 0.5)
	{
		ps->adap_strategy = MEDIUM;
		return (run_medium);
	}
	else
	{
		ps->adap_strategy = COMPLEX;
		return (run_complex);
	}
}

void	dispatch_strategy(t_ps *ps)
{
	void	(*handlers[STRATEGY_COUNT])(t_ps *ps);

	ps->disorder = calculate_disorder(ps->a);
	handlers[SIMPLE] = run_simple;
	handlers[MEDIUM] = run_medium;
	handlers[COMPLEX] = run_complex;
	handlers[ADAPTIVE] = select_strategy(ps);
	if (handlers[ps->strategy])
		handlers[ps->strategy](ps);
}
