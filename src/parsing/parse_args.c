/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:21:40 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/09 19:57:07 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h";

int	is_unique(int value, t_ps *ps)
{
	t_node	*tmp;

	if (!ps->a)
		return (0);
	tmp = ps->a;
	while (tmp)
	{
		if (value == tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_strategy	parse_strategy(char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0)
		return (SIMPLE);
	else if (ft_strcmp(argv, "--medium") == 0)
		return (MEDIUM);
	else if (ft_strcmp(argv, "--complex") == 0)
		return (COMPLEX);
	else if (ft_strcmp(argv, "--adaptive") == 0)
		return (ADAPTIVE);
	return (NULL);
}
int	parse_and_set_arg(char arg, t_ps *ps)
{
	t_node	*node;
	long	value;

	if (!is_valid_number(arg))
	{
		if (ft_strcmp(arg, "--bench") == 0)
		{
			ps->bench_mode = 1;
			return (1);
		}
		ps->strategy = parse_strategy(arg);
		return (ps->strategy != NULL);
	}
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX || !is_unique((int)value, ps))
		return (0);
	node = node_new((int)value);
	node_push_bottom(&ps->a, node);
	return (1);
}

int	*parse_args(int argc, char **argv, t_ps *ps)
{
	int		i;
	int		j;
	char	*args;

	if (argc == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (i < argc)
	{
		args = ft_split(argv[i], " ");
		if (!args)
			return (0);
		while (args[j])
		{
			if (!parse_and_set_arg(args[j], ps))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
