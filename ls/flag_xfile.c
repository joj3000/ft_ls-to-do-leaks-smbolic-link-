/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xfiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:08:26 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/18 20:17:03 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	flag_xfiles(int ac, char **av)
{
	int i;
	int count;

	count = 0;
	i = 1;
	while (i != ac)
	{
		if (!(av[i][0] == '-'))
			count++;
		i++;
	}
	return (count);
}

/*
**int main(int ac, char **av)
**{
**	printf("count = %d\n", flag_xfiles(ac, av));
**}
*/
