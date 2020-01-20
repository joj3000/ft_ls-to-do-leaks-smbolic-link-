/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permi_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:14:49 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/12 19:57:21 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*permi_conv(mode_t mode) 
{
	char	*end;
  	char	*chars;
	int		i;
	
	i = 0;
	chars = "rwxrwxrwx";
  	if (!(end = (char *)malloc(sizeof(char) * 10)))
		return (NULL);
	while (i < 9)
	{
		end[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
		i++;
	}
	end[i] = '\0';
	return (end);
}

/*
int main()
{
	//mode_t mode = -32348;
	mode_t mode = 16877;

	printf("%s\n", permi_conv(mode));
}
*/
