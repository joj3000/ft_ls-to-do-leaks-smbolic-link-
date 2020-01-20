/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:07:16 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 16:27:57 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		*strdup_free(char *s1)
{
	char	*str;
	int		i;

	i = ft_strln(s1);
	if (!(str = malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

/*
**int main()
**{
**	char s1[] = "hello";
**	printf("%s\n", ft_strdup(s1));
**}
*/
