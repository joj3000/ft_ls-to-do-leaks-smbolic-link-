/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:52:31 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 12:04:48 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = ft_strln(s1);
	if (!(str = malloc(sizeof(*str) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
**int main()
**{
**	char s1[] = "hello";
**	printf("%s\n", ft_strdup(s1));
**}
*/
