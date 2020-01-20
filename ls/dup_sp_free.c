/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_sp_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:43:24 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 21:01:36 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		*dup_sp_free(char *s1, int nb)    
{
	char	*str;
	int		i;
	int		j;
	int		count;

	count =  nb - ft_strln(s1);
	if (!(str = malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	i = 0;
	while (count != 0)
	{
		str[i] = ' ';
		i++;
		count--;
	}
	j = 0;
	while (s1[j] != '\0')
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

/*
**int main()
**{
**	char *s1;
**	s1 = ft_strdup("hello");
**	printf("%s\n", dup_sp_free(s1, 10));
**}
*/
