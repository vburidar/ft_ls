/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:58:02 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:24:12 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_ls.h"

/*
** ft_print_lst check the elements in lst and print their attributes one after
** the other.
** Two different functions are used whether the 'l' flag is activated or not
** - ft_printf for normal cases
** - ft_printl is used if the 'l' flag is activated
**
** Also the files '.' and '..' are not printed (except if 'a' flag is active)
** but files with path starting with './' and '../' must be printed
*/

void	ft_print_lst(t_lst *lst, char *flag, int i)
{
	while (lst->elem.name && ft_strchr(flag, 'l') == NULL)
	{
		if ((lst->elem.name[0] == '.' && lst->elem.name[1] != '/'
				&& lst->elem.name[1] != '.'
				&& ft_strchr(flag, 'a') == NULL)
				|| ((lst->elem.rights[0]) == 'd' && i == 0))
			;
		else if ((lst->elem.name[0] == '.' && lst->elem.name[1] == '.'
				&& lst->elem.name[2] != '/'
				&& ft_strchr(flag, 'a') == NULL)
				|| ((lst->elem.rights[0]) == 'd' && i == 0))
			;
		else if (ft_strchr(flag, 'l') == NULL)
			ft_printf("%s\n", lst->elem.name);
		lst = lst->nxt;
	}
	if (ft_strchr(flag, 'l'))
		ft_printl(lst, flag, i);
}
