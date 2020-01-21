/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_bytime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:40:05 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/21 09:48:46 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		correct_sort(t_lst *list)
{
	t_lst	*i;
	t_lst	*j;

	i = list;
	while (i->next != NULL)
	{
		j = i->next;
		if (i->mtime == j->mtime)
			lst_swap(i);
		i = i->next;
	}
}

void			lst_sort_bytime(t_lst *list)
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
			if (i->mtime < j->mtime)
			{
				lst_swap(i);
				flag = 1;
			}
			i = i->next;
		}
		i = list;
	}
	correct_sort(list);
}

/*
**int main()
**{
**	p_lst *list;
**	p_lst *toaddt;
**	p_lst *toaddu;
**	p_lst *toaddv;
**
**	list = (p_lst *)malloc(sizeof(p_lst));
**	toaddt = (p_lst *)malloc(sizeof(p_lst));
**	toaddu = (p_lst *)malloc(sizeof(p_lst));
**	toaddv = (p_lst *)malloc(sizeof(p_lst));
**
**	unsigned int	s;
**	unsigned int	t;
**	unsigned int	u;
**	unsigned int	v;
**
**	s = (int*)malloc(sizeof(int));
**	t = (int*)malloc(sizeof(int));
**	u = (int*)malloc(sizeof(int));
**	v = (int*)malloc(sizeof(int));
**
**	s = 1561;
**	t = 894646;
**	u = 4899;
**	v = 894;
**
**	list->mtime = s;
**	toaddt->mtime = t;
**	toaddu->mtime = u;
**	toaddv->mtime = v;
**	lst_pushback(list, toaddt);
**	lst_pushback(list, toaddu);
**	lst_pushback(list, toaddv);
**
**	lst_sort_bytime(list);
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
