/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pushback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 10:23:32 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 16:02:30 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	lst_pushback(p_lst *list, p_lst *toadd)
{
	while (list->next != NULL)
		list = list->next;
	list->next = toadd;
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
*	list = lst_newname(s);
**
**	lst_pushback(list, toadd);
**		while (list)
**		{
**		printf("%s\n", list->name);
*			list = list->next;
**		}
**
**
**}
*/
