/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenriq <pahenriq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:30:00 by pahenriq          #+#    #+#             */
/*   Updated: 2026/08/02 16:31:08 by pahenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_cnt_digits(unsigned long n, int base)
{
	if (n < (unsigned long)base)
		return (1);
	return (1 + ft_cnt_digits(n / base, base));
}

void	ft_alloc_digits(char **str_charset, unsigned long n, int base, int *i)
{
	if (n < (unsigned long)base)
	{
		str_charset[0][*i] = str_charset[1][n];
		return ;
	}
	ft_alloc_digits(str_charset, n / base, base, i);
	(*i)++;
	str_charset[0][*i] = str_charset[1][n % base];
}

char	*ft_utoa_base(unsigned long n, int base, char *charset)
{
	char	*str_charset[2];
	char	*str;
	int		i;

	if (base < 2 || base > 36 || !charset)
		return (NULL);
	str = malloc(ft_cnt_digits(n, base) + 1);
	if (!str)
		return (NULL);
	str_charset[0] = str;
	str_charset[1] = charset;
	i = 0;
	ft_alloc_digits(str_charset, n, base, &i);
	str[i + 1] = '\0';
	return (str);
}
