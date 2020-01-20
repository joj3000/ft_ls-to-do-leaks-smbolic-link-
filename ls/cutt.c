/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:07:17 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 15:37:54 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*cutt(char *old)
{
	char 	*new;
	int		i;
	int		j;

	if (!(new = (char *)malloc(sizeof(char) * 13)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < 4)
		i++;
	while (i < 16)
		new[j++] = old[i++];
	new[j] = 0;
	return (new);
}

/*
**int main()
**{
**	char *old;
**	old = "Sun Jan 12 12:06:30 2020";
**
**	printf("%s\n", cutt(old));
**}
*/
