/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:22:07 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 13:20:58 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*strjoin_free(char *s1, char *s2, char *tmp)
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
	free(tmp);
	return (str);
}

/*
**#include <stdio.h>
**int main()
**{
**	while (1){
**	char s1[] = "ceci est un ";
**	char s2[] = "test !";
**	char *s3;
**	char *tmp;
***	tmp = malloc(sizeof(char ) + 1);
**	tmp[0] = '1';
**	tmp[1] = 0;
**	s3 = strjoin_free(s1, s2, tmp);
**	free(s3);
**}
**}
*/
