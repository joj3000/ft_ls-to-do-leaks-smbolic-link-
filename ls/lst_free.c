/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 10:35:55 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 20:40:03 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_free(p_lst *list)
{
	p_lst *cpy;
	int i;

	i = 0;
	while (list)
	{
		cpy = list->next;
		free(list->type);
		free(list->permi);
		free(list->links);
		free(list->user);
		free(list->group);
		free(list->size);
		free(list->tmodif);
		free(list->name);
		if (i-- == 0 && ft_strln(list->path) != 0)		
			free(list->path);
		list->next = NULL;
		free(list);
		list = cpy;
	}
	free(list);
}

/*
**int main()
**{
**	p_lst *list;
**	p_lst *toadd;
**	char *s;
**	char *t;
**
**	s = ft_strdup("bonjour");
**	t = ft_strdup("yoyo");
**
**	toadd = lst_newname(t);
**	list = lst_newname(s);
**
**	lst_pushback(list, toadd);
**	
**	lst_free(list);
**
**}
*/
