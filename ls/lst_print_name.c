/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:11:22 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 21:57:30 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_print_name(t_lst *list, char *options, int xfiles)
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
		if (!(list->name[0] == '.'))
		{
			putstr(list->name);
			write(1, "\n", 1);
		}
		list = list->next;
	}
}
