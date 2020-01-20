/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_blocksize_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:35:25 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 16:06:10 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

long int	print_blocksize_l(p_lst *list)
{
	long int count;

	count = 0;
	while (list)
	{
		if (!(list->name[0] == '.'))
			count += list->blocks;
		list = list->next;
	}
	write(1, "total ", 6);
	ft_putllnbr(count);
	write(1, "\n", 1);
	return (count);
}
