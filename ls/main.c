/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:09:06 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/21 09:28:03 by jerbs            ###   ########.fr       */
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

int		enter_folder_recursively(char *path, char *options, int xfiles)
{
	DIR			*dir_p;
	t_dirent	*dp;
	t_stat		*stats;
	char		*tmp;
	int			flag;

	flag = 1;
	if (!(dir_p = opendir(path)))
		return (-1);
	stats = (t_stat*)malloc(sizeof(t_stat));
	tmp = (char *)malloc(sizeof(char) * 1);
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
	free_stuff(stats, path, tmp);
	return (1);
}

void	main_part4(int ac, char *options, int xfiles)
{
	if (ac == 1)
		enter_folder_recursively(".", options, xfiles);
}

void	main_part2(char **av, int i)
{
	write(1, "ls: ", 4);
	putstr(av[i]);
	write(1, ": No such file or directory\n", 28);
}

void	main_part3(int i, char **av, char *options)
{
	if (is_bralrt(av[i]) == 0)
	{
		free(options);
		exit(0);
	}
}

int		main(int ac, char **av)
{
	char	*options;
	int		i;
	int		xfiles;

	i = 0;
	xfiles = flag_xfiles(ac, av);
	options = ft_strdup("0");
	main_part4(ac, options, xfiles);
	while (++i != ac)
	{
		if (av[i][0] != '-')
			break ;
		main_part3(i, av, options);
		options = add_options(av[i], options);
	}
	if (i-- != ac)
		while (++i != ac)
		{
			if (no_file_param(ac, av) == 1)
				enter_folder_recursively(".", options, xfiles);
			else if (enter_folder_recursively(av[i], options, xfiles) == -1)
				main_part2(av, i);
		}
	else if (ac != 1)
		enter_folder_recursively(".", options, xfiles);
}
