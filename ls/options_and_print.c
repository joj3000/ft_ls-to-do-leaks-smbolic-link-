/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:57:29 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/20 22:03:00 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	options_and_print(t_lst *list, char *options, int xfiles)
{
	lst_sort_byname(list);
	if (is_in(options, 't') == 1)
		lst_sort_bytime(list);
	if (is_in(options, 'r') == 1)
		lst_sort_rev(list, options);
	if (is_in(options, 'a') == 1 && is_in(options, 'l') == 0)
		lst_print_all(list, options, xfiles);
	else if (is_in(options, 'l') == 1)
	{
		if (is_in(options, 'a') == 1)
			lst_print_max(list, options, xfiles);
		else
			lst_print_l(list, options, xfiles);
	}
	else
		lst_print_name(list, options, xfiles);
}
