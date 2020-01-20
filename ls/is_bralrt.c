/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bralrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:18:42 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/18 20:20:17 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int is_bralrt(char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' && ft_strln(s) == 1)
		return (2);
	i++;
	while (s[i])
	{
		if (s[i] != 'R' && s[i] != 'a'
		&& s[i] != 'l' && s[i] != 'r'
		&& s[i] != 't')
		{
			write(1, "usage: ls [-Ralrt] [file...]\n", 29);
			return (0);
		}
		i++;
	}
	return (1);
}
