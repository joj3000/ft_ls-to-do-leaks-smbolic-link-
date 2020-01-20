/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:09:06 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 20:57:50 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/dir.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include "ls.h"
#include <time.h>

					// leaks = print_max + .. 
					// avec dup_sp_free (= chelou)
					// et size_sp_updt


void	options_and_print(p_lst *list, char *options, int xfiles)
{
	lst_sort_byname(list);
	if (is_in(options, 't') == 1)
		lst_sort_bytime(list);
	if (is_in(options, 'r') == 1)
		lst_sort_rev(list, options);
	if (is_in(options, 'a') == 1 && is_in(options, 'l') == 0)
		lst_print_all(list, options, xfiles);
	else if (is_in(options, 'l') == 1)
	{	
		if (is_in(options, 'a') == 1)
			lst_print_max(list, options, xfiles);
		else
			lst_print_l(list, options, xfiles);
	}
	else
		lst_print_name(list, options, xfiles);
}

int		print_folder_content(char *path, char *options, int xfiles)
{
	p_lst *list;
	p_stat *stats;
	p_dirent *dp;
	char *tmp;
	DIR *dir_p;

	if (!(dir_p = opendir(path)))
		return (-1);
	stats = (p_stat*)malloc(sizeof(p_stat));
	dp = (p_dirent *)malloc(sizeof(p_dirent));
	tmp = (char *)malloc(sizeof(char));
	if (!(list = (p_lst *)malloc(sizeof(p_lst))))
		return (0);
	list = NULL;
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
	free(stats);
	free(dp);
	free(tmp);
	lst_free(list); /////////////////////
	closedir(dir_p);
	//free(path);
	return (1);
}

int enter_folder_recursively(char *path, char *options, int xfiles)
{
	DIR	*dir_p;
	p_dirent *dp;
	p_stat *stats;
	char *tmp;
	int flag;

	flag = 1;
	stats = (p_stat*)malloc(sizeof(p_stat));
	dp = (p_dirent *)malloc(sizeof(p_dirent));
	tmp = (char *)malloc(sizeof(char) * 1);
	if (!(dir_p = opendir(path)))
		return (-1);
	path = ft_strjoin(path, "/");
	while ((dp = readdir(dir_p)))
	{
		if (flag-- == 0)
			print_folder_content(path, options, xfiles);
		lstat(tmp = strjoin_free(path, dp->d_name, tmp), stats);
		if (S_ISDIR(stats->st_mode) != 0 && ft_strcmp(dp->d_name, ".") != 0
		&& ft_strcmp(dp->d_name, "..") != 0 && is_in(options, 'R') == 1)
				enter_folder_recursively(tmp = strdup_free(tmp), options, xfiles);
	}
	closedir(dir_p);
	free(stats);
	free(dp);
	free(path);
	free(tmp);
	return (1);
}

int	no_file_param(int ac, char **av)
{
	int i;

	i = 0;
	while (i != ac)
	{
		if (!(av[i][0] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	char 	*options;
	int		i;
	int		xfiles;

	i = 1;
	xfiles = flag_xfiles(ac, av);
	options = (char *)malloc(sizeof(char) * 2);
	options[0] = '0';
	options[1] = 0;
	if (ac == 1)
		enter_folder_recursively(".", options, xfiles);
	while (i != ac)
	{
		if (av[i][0] != '-')
			break;
		if (is_bralrt(av[i]) == 0)
		{	
			free(options);
			return (0);
		}
		options = strdup_free(add_options(av[i], options));
		i++;
	}
	if (i != ac)
		while (i != ac)
		{
			if (no_file_param(ac, av) == 1)
				enter_folder_recursively(".", options, xfiles);
			else if (enter_folder_recursively(av[i], options, xfiles) == -1)
			{	
				write(1, "ls: ", 4);
				putstr(av[i]);
				write(1, ": No such file or directory\n", 28);
			}
			i++;
		}
	else if (ac != 1)
		enter_folder_recursively(".", options, xfiles);


	free(options);

}
