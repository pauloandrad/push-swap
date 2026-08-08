/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: pahenriq <pahenriq@student.42sp.org.br>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/08/08 13:29:16 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/08 13:29:16 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


float	calculate_disorder(t_node *top)
{
	int err;
	int total_pairs;

	t_node i;
	t_node j;

	errs = 0;
	total_pairs = 0;

	i = top;

	while (top->next != NULL)
	{
		j = i->next;
		while (j->next != NULL)
		{
			total_pairs += 1;
			if (i->value > j->value)
				errs += 1;
		}
		i = i->next;
	}

	return (errs / total_pairs);
}