/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_byname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:25:45 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 15:29:36 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_sort_byname(p_lst *list)
{
	p_lst	*i;
	p_lst	*j;
	int		flag;

	flag = 1;
	i = list;
	while (flag == 1)
	{
		flag = 0;
		while (i->next != NULL)
		{
			j = i->next;
			if (ft_strcmp(i->name, j->name) > 0)
			{
				lst_swap(i);
				flag = 1;
			}
			i = i->next;
		}
		i = list;
	}
}

/*
**int main()
**{
**	p_lst *list;
**	p_lst *toaddt;
**	p_lst *toaddu;
**	p_lst *toaddv;
**	char *s;
**	char *t;
**	char *u;
**	char *v;
**
**	s = ft_strdup("b");
**	t = ft_strdup("a");
**	u = ft_strdup("e");
**	v = ft_strdup("c");
**
**	toaddt = lst_newname(t);
**	toaddu = lst_newname(u);
**	toaddv = lst_newname(v);
**	list = lst_newname(s);
**
**	lst_pushback(list, toaddt);
**	lst_pushback(list, toaddu);
**	lst_pushback(list, toaddv);
**	
**	lst_sort(list);
**
**	lst_print(list);
**
**
**	while (list)
**		{
**		printf("%s\n", list->name);
**			list = list->next;
**		}
**}
*/
