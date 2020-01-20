/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:24:32 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 15:41:02 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "ls.h"

int			error_char(int ac, char **av)
{
	int i;

	i = 1;
	if (ac <= 1)
		return (0);
	while (ac != 1)
	{
		while (av[ac - 1][i])
		{
			if (av[ac - 1][i] != 'l' && av[ac - 1][i] != 'a'
			&& av[ac - 1][i] != 'r' && av[ac - 1][i] != 'R'
			&& av[ac - 1][i] != 't') 
				return (1);
			i++;
		}
		i = 1;
		ac--;
	}
	return(0);
}


int			error_front(int ac, char **av)
{
	int i;

	i = 0;
	if (ac <= 1)
		return (0);
	while (ac != 1)
	{
		if (av[ac - 1][0] != '-')
			return (1);
		ac--;
	}
	return(0);
}

int			error_in(int ac, char **av)
{
	int i;

	i = 1;
	if (ac <= 1)
		return (0);
	while (ac != 1)
	{
		while (av[ac - 1][i])
		{
			if (av[ac - 1][i] == '-')
				return (1);
			i++;
		}
		i = 1;
		ac--;
	}
	return(0);
}

int			error_solo(int ac, char **av)
{
	int i;

	i = 1;
	if (ac <= 1)
		return (0);
	while (ac != 1)
	{
		if (ft_strln(av[ac -1]) == 1 && av[ac -1][0] == '-')
			return (1);
		ac--;
	}
	return(0);
}


int			errors(int ac, char **av)
{
	if (error_in(ac, av) == 1 || error_front(ac, av) == 1 ||
		error_solo(ac, av) == 1 || error_char(ac, av) == 1)
		return (1);
	else
		return (0);
}


**#include <stdio.h>
**int main(int ac, char **av)
**{
**	printf("ERROR = %d\n", errors(ac, av));
**	printf("solo = %d\n", error_solo(ac, av));
**	printf("in = %d\n", error_in(ac, av));
**	printf("front = %d\n", error_front(ac, av));
**	printf("char = %d\n", error_char(ac, av));
**}
*/
