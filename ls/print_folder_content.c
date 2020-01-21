/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_folder_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:20:03 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/21 09:27:19 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	pfc_2(t_stat *stats, char *tmp, t_lst *list, DIR *dir_p)
{
	free_stuff2(stats, tmp, list);
	closedir(dir_p);
}

int		print_folder_content(char *path, char *options, int xfiles)
{
	t_lst		*list;
	t_stat		*stats;
	t_dirent	*dp;
	char		*tmp;
	DIR			*dir_p;

	if (!(dir_p = opendir(path)))
		return (-1);
	stats = (t_stat*)malloc(sizeof(t_stat));
	dp = NULL;
	tmp = NULL;
	while ((dp = readdir(dir_p)))
	{
		lstat(tmp = strjoin_free(path, dp->d_name, tmp), stats);
		if (list == NULL)
		{
			list = lst_new(dp, stats);
			list->path = filter_tmp(tmp);
		}
		else
			lst_pushback(list, lst_new(dp, stats));
	}
	options_and_print(list, options, xfiles);
	pfc_2(stats, tmp, list, dir_p);
	return (1);
}
