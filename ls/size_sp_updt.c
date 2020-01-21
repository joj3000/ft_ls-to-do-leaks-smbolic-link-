/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_sp_updt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:05:06 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 22:04:16 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		sp_size(t_lst *list)
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

void			size_sp_updt(t_lst *list)
{
	while (list != NULL)
	{
		list->size = dup_sp_free(list->size, sp_size(list));
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
**	list->size = ft_strdup("tamere");
**	list2->size = ft_strdup("tamereaussi");
**
**	list->next = list2;
**	list2->next = NULL;
**
**	size_sp_updt(list);
**
**	p_lst *cpy;
**	while (list)
**	{
**		cpy = list->next;
**		free(list->size);
**		free(list);
**		list = cpy;}
**}}
*/
