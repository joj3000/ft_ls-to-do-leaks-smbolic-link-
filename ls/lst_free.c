/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 10:35:55 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 21:55:29 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_free(t_lst *list)
{
	t_lst	*cpy;
	int		i;

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
**	while (1)
**{	p_lst *list;
**	p_lst *toadd;
**	p_lst *toadd2;
**
**	list = (p_lst *)malloc(sizeof(p_lst));
**	toadd = (p_lst *)malloc(sizeof(p_lst));
**	toadd2 = (p_lst *)malloc(sizeof(p_lst));
**
**	list->type = ft_strdup("1");
**	list->permi = ft_strdup("1");
**	list->links = ft_strdup("1");
**	list->user = ft_strdup("1");
**	list->group = ft_strdup("1");
**	list->size = ft_strdup("1");
**	list->tmodif = ft_strdup("1");
**	list->name = ft_strdup("1");
**	list->path = ft_strdup("1");
**
**
**	toadd->type = ft_strdup("1");
**	toadd->permi = ft_strdup("1");
**	toadd->links = ft_strdup("1");
**	toadd->user = ft_strdup("1");
**	toadd->group = ft_strdup("1");
**	toadd->size = ft_strdup("1");
**	toadd->tmodif = ft_strdup("1");
**	toadd->name = ft_strdup("1");
**
**
**	toadd2->type = ft_strdup("1");
**	toadd2->permi = ft_strdup("1");
**	toadd2->links = ft_strdup("1");
**	toadd2->user = ft_strdup("1");
**	toadd2->group = ft_strdup("1");
**	toadd2->size = ft_strdup("1");
**	toadd2->tmodif = ft_strdup("1");
**	toadd2->name = ft_strdup("1");
**
**
**	toadd2->next = NULL;
**	toadd->next = toadd2;
**	list->next = toadd;
**
**	printf("%s\n", list->type);
**	lst_free(list);
***
**}}
*/
