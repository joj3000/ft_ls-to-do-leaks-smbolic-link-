/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_sp_updt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:01:19 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 15:10:46 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		sp_links(p_lst *list)
{
	static int count = 0;

	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		if (ft_strln(list->links) > count)
			count = ft_strln(list->links);
		list = list->next;
	}
	return (count);
}

void			links_sp_updt(p_lst *list)
{
	while (list != NULL)
	{
		list->links = dup_sp_free(list->links, sp_links(list));
		list = list->next;
	}
}
