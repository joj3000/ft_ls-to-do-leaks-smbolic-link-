/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:12:18 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 15:33:28 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_print_all(p_lst *list, char *options, int xfiles)
{
	if (is_in(options, 'R') == 0)
		if (xfiles >= 2)
		{	
			putstr("\n");
			putstr(list->path);
			putstr(":\n");
		}
	if (is_in(options, 'R') == 1)
		if (ft_strcmp(list->path, "") != 0)
		{	
			putstr("\n");
			putstr(list->path);
			putstr(":\n");
		}
	while (list)
	{
		putstr(list->name);
		write(1, "\n", 1);
		list = list->next;
	}
}
