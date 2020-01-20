/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 21:03:39 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 15:41:41 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**b     Block special file.
**c     Character special file.
**d     Directory.
**l     Symbolic link.
**s     Socket link.
**p     FIFO.
**-     Regular file.
*/

#include "ls.h"

char	*file_type(mode_t m)
{
	if (S_ISDIR(m) != 0)
		return (ft_strdup("d")); 
	else if (S_ISREG(m) != 0)
		return (ft_strdup("-")); 	
	else if (S_ISCHR(m) != 0)
		return (ft_strdup("c")); 	
	else if (S_ISBLK(m) != 0)
		return (ft_strdup("b")); 	
	else if (S_ISFIFO(m) != 0)
		return (ft_strdup("p")); 	
	else if (S_ISLNK(m) != 0)
		return (ft_strdup("l")); 	
	else if (S_ISSOCK(m) != 0)
		return (ft_strdup("s"));
	else
		return (ft_strdup("?"));
}
