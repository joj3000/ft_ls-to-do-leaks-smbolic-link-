/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:22:35 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/14 16:22:37 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static	int	modulo(long long int n)
{
	long long int k;
	long long int l;

	if (n != 0)
	{
		if (n < 0)
			n *= -1;
		k = n % 10;
		l = (n - k) / 10;
		modulo(l);
		ft_putchar(k + '0');
		return (0);
	}
	else
		return (0);
}

void		ft_putllnbr(long long int n)
{
	if (n == 0)
		write(1, "0", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		modulo(n);
	}
	else
		modulo(n);
}

/*
**int main()
**{
**	long long int a = -561616519686;
**
**	ft_putllnbr(a);
**}
*/
