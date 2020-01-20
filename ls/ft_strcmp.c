/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:48:30 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 15:27:10 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] == c_s2[i] && c_s1[i] != 0 && c_s2[i] != 0)
		i++;
	return (c_s1[i] - c_s2[i]);
}
