/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:02:15 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 22:13:50 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		count_til_slash(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] != '/')
		i--;
	return (i);
}

char	*filter_tmp(char *tmp)
{
	int		i;
	char	*new;
	char	*case_dot;

	i = 0;
	new = (char *)malloc(sizeof(char) * count_til_slash(tmp) + 1);
	while (i < count_til_slash(tmp))
	{
		new[i] = tmp[i];
		i++;
	}
	new[i] = 0;
	if (ft_strcmp(new, ".") == 0)
	{
		free(new);
		case_dot = "";
		return (case_dot);
	}
	return (new);
}

/*
**int main()
**{
**	while(1){
**	char *s;
**	printf("%d\n", count_til_slash(".rhterth/w5ywrhr/wrwh/"));
**	printf("%s", s = filter_tmp(".rhterth/w5ywrhr/wrwh/"));
**	free(s);}
**}
*/
