/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_blocksize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:16:59 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 22:12:24 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

long int	print_blocksize(t_lst *list)
{
	long int count;

	count = 0;
	while (list)
	{
		count += list->blocks;
		list = list->next;
	}
	write(1, "total ", 6);
	ft_putllnbr(count);
	write(1, "\n", 1);
	return (count);
}
