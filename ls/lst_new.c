/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:07:30 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 19:05:52 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

p_lst	*lst_new(p_dirent *dp, p_stat *stats)
{
	p_lst *list;

	if (!(list = (p_lst *)malloc(sizeof(p_lst))))
		return (NULL);
	list->type = file_type(stats->st_mode);
	list->permi = permi_conv(stats->st_mode);
	list->links = ltoa((long int)stats->st_nlink);
	list->user = ft_strdup(getpwuid(stats->st_uid)->pw_name);
	list->group = ft_strdup(getgrgid(stats->st_gid)->gr_name);
	list->size = ltoa((long int)stats->st_size);
	list->tmodif = cutt(ctime(&stats->st_mtimespec.tv_sec));
	list->name = ft_strdup(dp->d_name);
	list->blocks = (long int)stats->st_blocks;
	list->mtime = (unsigned int)stats->st_mtimespec.tv_sec;
	list->next = NULL;
	return (list);
}

/*
**int main()
**{
**	char *s;
**	p_lst *list;
**	s = ft_strdup("");
**
**	list = lst_newname(s);
**	printf("%s\n", list->name);
**}
*/
