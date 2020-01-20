/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:18:07 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 16:28:24 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*strjoin_free1(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strln(s1) + ft_strln(s2) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		str[i++] = s1[k++];
	k = 0;
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	free(s1);
	return (str);
}

/*
**#include <stdio.h>
**int main()
**{
**	char s1[] = "ceci est un ";
**	char s2[] = "test !";
**
**	printf("%s", ft_strjoin(s1, s2));
**}
*/
