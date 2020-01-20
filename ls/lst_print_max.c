/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:25:35 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 21:01:45 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	print_shit(p_lst *list)
{
		putstr(list->type);
		putstr(list->permi);
		putstr("  ");
		putstr(list->links);
		putstr(" ");
		putstr(list->user);
		putstr("  ");
		putstr(list->group);
		putstr("  ");
		putstr(list->size);
		putstr(" ");
		putstr(list->tmodif);
		putstr(" ");
		putstr(list->name);
		putstr("\n");
}

void		lst_print_max(p_lst *list, char *options, int xfiles)
{
	links_sp_updt(list);
	size_sp_updt(list);
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
	print_blocksize(list);
	while (list != NULL)
	{
		print_shit(list);
		list = list->next;
	}
}
