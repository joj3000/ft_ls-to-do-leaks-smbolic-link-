/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:13:36 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/12 19:13:59 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static	void	modulo_count(long int n, long int *count)
{
	long long int r;

	if (n >= 1)
	{
		r = n % 10;
		n = (n - r) / 10;
		modulo_count(n, count);
		*count = *count + 1;
	}
}

static long int	malloc_count(long int n)
{
	long int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	if (n < 0)
		n *= -1;
	modulo_count(n, &count);
	return (count);
}

static void		modulo_put_in_str(long int n, char *str,
				char *str_base, long int *index)
{
	long long int r;

	if (n < 0)
		n *= -1;
	if (n >= 1)
	{
		*index = *index - 1;
		r = n % 10;
		n = (n - r) / 10;
		str[*index] = str_base[r];
		modulo_put_in_str(n, str, str_base, index);
	}
}

char			*ltoa(long int n)
{
	char				*str_base;
	char				*str;
	long int		index;
	long int		end;

	str_base = "0123456789";
	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	index = malloc_count(n);
	end = malloc_count(n);
	if (!(str = (char *)malloc(sizeof(char) * (malloc_count(n) + 1))))
		return (0);
	modulo_put_in_str(n, str, str_base, &index);
	str[end] = '\0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*
#include <stdio.h>
int main()
{
	printf("%s", ltoa(-4294967295));
}
*/
