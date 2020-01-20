/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_sp_updt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:05:06 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 16:07:15 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		sp_size(p_lst *list)
{
	static int count = 0;

	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		if (ft_strln(list->size) >= count)
			count = ft_strln(list->size);
		list = list->next;
	}
	return (count);
}

void			size_sp_updt(p_lst *list)
{
	while (list != NULL)
	{
		list->size = dup_sp_free(list->size, sp_size(list));
		list = list->next;
	}
}
