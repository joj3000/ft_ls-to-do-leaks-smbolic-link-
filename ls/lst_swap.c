/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:49:27 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 11:42:39 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
void swap(p_lst **a, p_lst **b) {
    p_lst *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_node(p_lst **first, p_lst **second)
{
    p_lst *tmp;
	
	tmp = *first;
    *first = *second;
    *second = tmp;
}

void	swap_char(char **s, char **t)
{
	void *tmp;

	tmp = *s;
	*s = *t;
	*t = tmp;
}
*/
/*
void	swap_int(unsigned int *a, unsigned int *b)
{
	unsigned int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
*/
void	lst_swap(p_lst *lst)
{
	char *tmp;
	long int temp;
	unsigned int tp;

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


//	swap_int(&lst->mtime, &lst->next->mtime);

}
/*
void	type_permi_links_mt(p_lst *i, p_lst *j)
{
	char	*tmp;
//	int		cpy;
	
	tmp = i->type;
	i->type = j->type;
	j->type = tmp;

	tmp = i->permi;
	i->permi = j->permi;
	j->permi = tmp;
	
	tmp = i->links;
	i->links = j->links;
	j->links = tmp;

//	cpy = i->mtime;
//	i->mtime = j->mtime;;
//	j->mtime = cpy;;
//	tmp = i->mtime;
//	i->mtime = j->mtime;
//	j->mtime = tmp;
}

void	group_size_tm_name(p_lst *i, p_lst *j)
{
	char *tmp;

	tmp = i->group;
	i->group = j->group;
	j->group = tmp;

	tmp = i->size;
	i->size = j->size;
	j->size = tmp;

	tmp = i->tmodif;
	i->tmodif = j->tmodif;
	j->tmodif = tmp;
	
	tmp = i->name;
	i->name = j->name;
	j->name = tmp;
}


void	lst_swap_param(p_lst *i, p_lst *j)
{
//	swap_char(&(i->type), &(j->type));
//	swap_char(&(i->permi), &(j->permi));
//	swap_char(&(i->links), &(j->links));
//	swap_char(&(i->name), &(j->name));
//	swap_char(&(i->group), &(j->group));
//	swap_char(&(i->size), &(j->size));
//	swap_char(&(i->tmodif), &(j->tmodif));
//	swap_char(&(i->links), &(j->links));
//	swap_char(&(i->mtime), &(j->mtime));

//	type_permi_links_mt(i, j);
//	group_size_tm_name(i, j);
}


int main()
{
	
	char *s;
	char *t;
	s = ft_strdup("s");
	t = ft_strdup("t");

	swap_test(&s, &t);	
	
	
	printf("%s\n", t);	
	

	
	
	
	
	
	p_lst *list;
	p_lst *list1;

	list = (p_lst *)malloc(sizeof(p_lst));
	list1 = (p_lst *)malloc(sizeof(p_lst));

	char *s;
	char *t;
	char *u;
	char *v;
	char *w;
	char *x;
	char *y;
	char *z;
	unsigned int zz;

	s = ft_strdup("s");
	t = ft_strdup("t");
	u = ft_strdup("u");
	v = ft_strdup("v");
	w = ft_strdup("w");
	x = ft_strdup("x");
	y = ft_strdup("y");
	z = ft_strdup("z");
	zz = 0;

	char *s1;
	char *t1;
	char *u1;
	char *v1;
	char *w1;
	char *x1;
	char *y1;
	char *z1;
	unsigned int zz1;

	s1 = ft_strdup("s1");
	t1 = ft_strdup("t1");
	u1 = ft_strdup("u1");
	v1 = ft_strdup("v1");
	w1 = ft_strdup("w1");
	x1 = ft_strdup("x1");
	y1 = ft_strdup("y1");
	z1 = ft_strdup("z1");
	zz1 = 1;

	list->type = s;
	list->permi = t;
	list->links = u;
	list->user = v;
	list->group = w;
	list->size = x;
	list->tmodif = y;
	list->name = z;
	list->mtime = zz;

	list1->type = s1;
	list1->permi = t1;
	list1->links = u1;
	list1->user = v1;
	list1->group = w1;
	list1->size = x1;
	list1->tmodif = y1;
	list1->name = z1;
	list1->mtime = zz1;

	list->next = list1;
	while (list != NULL)
		{
			printf("%s\n", list->type);
			printf("%s\n", list->permi);
			printf("%s\n", list->links);
			printf("%s\n", list->user);
			printf("%s\n", list->group);
			printf("%s\n", list->size);
			printf("%s\n", list->tmodif);
			printf("%s\n", list->name);
			printf("%u\n", list->mtime);
			list = list->next;
		}



//	lst_print(list);
//swap_node(&list, &(list->next));
//swap_char(&(list->name), (&((list->next)->name));
//swap(&list, &list->next);
//swap(list, 2, 1);

//	ft_lstswap(list, list1);

	lst_print(list);


swap_test(list);

	lst_print(list);


	while (list != NULL)
		{
			printf("%s\n", list->type);
			printf("%s\n", list->permi);
			printf("%s\n", list->links);
			printf("%s\n", list->user);
			printf("%s\n", list->group);
			printf("%s\n", list->size);
			printf("%s\n", list->tmodif);
			printf("%s\n", list->name);
			printf("%u\n", list->mtime);
			list = list->next;
		}

	while (list)
		{
		printf("%s\n", list->name);
			list = list->next;
		}


}
*/
