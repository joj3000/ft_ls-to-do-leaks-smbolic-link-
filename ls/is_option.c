/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:39:56 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 22:06:44 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		is_option(int ac, char **av, char o)
{
	int i;

	i = 0;
	if (ac <= 1)
		return (0);
	while (ac != 1)
	{
		while (av[ac - 1][i])
		{
			if (av[ac - 1][i] == o)
				return (1);
			i++;
		}
		i = 0;
		ac--;
	}
	return (0);
}

char	*add_options(char *s, char *options)
{
	if (ft_strln(s) == 1)
		options = strjoin_free1(options, "0");
	if (is_in(s, 'l') == 1)
		options = strjoin_free1(options, "l");
	if (is_in(s, 'R') == 1)
		options = strjoin_free1(options, "R");
	if (is_in(s, 'r') == 1)
		options = strjoin_free1(options, "r");
	if (is_in(s, 'a') == 1)
		options = strjoin_free1(options, "a");
	if (is_in(s, 't') == 1)
		options = strjoin_free1(options, "t");
	return (options);
}

/*
**#include <stdio.h>
**int main()
**{
**	while (1){
**		char *s;
**		char *options;
**		options = ft_strdup("0");
**		s = "0lRrat";
**		options = add_options(s, options);
**		free(options);
**}}
*/
