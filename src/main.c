/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:43:28 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/09 18:08:49 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h";

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

int	*parse_arg(char arg, t_ps *ps)
{
	t_node	*node;

	if (is_valid_number(arg))
	{
		node = node_new(ft_atoi(arg));
		node_push_bottom(ps->a, node);
	}
	else if (ft_strcmp(arg, "--bench") == 0)
		ps->bench_mode = 1;
	else
	{
		ps->strategy = NULL;
		ps->strategy = parse_strategy(arg);
		if (!ps->strategy)
			exit(1); // add error handling
	}
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
		args = ft_split(argv[i]);
		while (args[j])
		{
			parse_arg(args[j], ps);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < argc)
	{
		tmp = argv[i];
		i++;
	}
	return (0);
}
