/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_sp_updt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:01:19 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 22:14:17 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		sp_links(t_lst *list)
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

void			links_sp_updt(t_lst *list)
{
	while (list != NULL)
	{
		list->links = dup_sp_free(list->links, sp_links(list));
		list = list->next;
	}
}

/*
**int main()
**{
**	while(1){
**	p_lst *list;
**	p_lst *list2;
**
**list = NULL;
**list2 = NULL;
**	list = (p_lst*)malloc(sizeof(p_lst));
**	list2 = (p_lst*)malloc(sizeof(p_lst));
**
**	list->links = ft_strdup("tamere");
**	list2->links = ft_strdup("tamereaussi");
**
**	list->next = list2;
**	list2->next = NULL;
**
**	links_sp_updt(list);
**	p_lst *cpy;
**	while (list)
**	{
**		cpy = list->next;
**		free(list->links);
**		free(list);
**		list = cpy;}
**}}
*/
