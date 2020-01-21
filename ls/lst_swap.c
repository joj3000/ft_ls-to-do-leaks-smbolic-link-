/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:49:27 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 21:59:54 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	part2(t_lst *lst)
{
	char			*tmp;

	tmp = lst->type;
	lst->type = lst->next->type;
	lst->next->type = tmp;
	tmp = lst->permi;
	lst->permi = lst->next->permi;
	lst->next->permi = tmp;
	tmp = lst->links;
	lst->links = lst->next->links;
	lst->next->links = tmp;
	tmp = lst->user;
	lst->user = lst->next->user;
	lst->next->user = tmp;
	tmp = lst->group;
	lst->group = lst->next->group;
	lst->next->group = tmp;
}

void	lst_swap(t_lst *lst)
{
	char			*tmp;
	long int		temp;
	unsigned int	tp;

	part2(lst);
	tmp = lst->size;
	lst->size = lst->next->size;
	lst->next->size = tmp;
	tmp = lst->name;
	lst->name = lst->next->name;
	lst->next->name = tmp;
	tmp = lst->tmodif;
	lst->tmodif = lst->next->tmodif;
	lst->next->tmodif = tmp;
	temp = lst->blocks;
	lst->blocks = lst->next->blocks;
	lst->next->blocks = temp;
	tp = lst->mtime;
	lst->mtime = lst->next->mtime;
	lst->next->mtime = tp;
}
