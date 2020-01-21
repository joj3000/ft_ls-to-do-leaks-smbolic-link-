/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:05:48 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 21:59:33 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_sort_revtime(t_lst *list)
{
	t_lst	*i;
	t_lst	*j;
	int		flag;

	flag = 1;
	i = list;
	while (flag == 1)
	{
		flag = 0;
		while (i->next != NULL)
		{
			j = i->next;
			if (i->mtime > j->mtime)
			{
				lst_swap(i);
				flag = 1;
			}
			i = i->next;
		}
		i = list;
	}
}

void	lst_sort_revname(t_lst *list)
{
	t_lst	*i;
	t_lst	*j;
	int		flag;

	flag = 1;
	i = list;
	while (flag == 1)
	{
		flag = 0;
		while (i->next != NULL)
		{
			j = i->next;
			if (ft_strcmp(i->name, j->name) < 0)
			{
				lst_swap(i);
				flag = 1;
			}
			i = i->next;
		}
		i = list;
	}
}

void	lst_sort_rev(t_lst *list, char *options)
{
	if (is_in(options, 't') == 1)
		lst_sort_revtime(list);
	else
		lst_sort_revname(list);
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
**	lst_sortrev(list);
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
