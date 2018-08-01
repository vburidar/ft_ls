/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:51:20 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:03:24 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "ft_printf.h"
#include "ft_ls.h"

void		ft_init_len(t_length *len)
{
	len->l_link = 0;
	len->l_oname = 0;
	len->l_gname = 0;
	len->l_size = 0;
	len->l_time = 0;
	len->l_minor = 0;
	len->l_major = 0;
}

/*
** ft_test_len compares the former max length with a new one
** and replace it if the new one is bigger
*/

int			ft_test_len(long value, int len_ref)
{
	char	*tmp;
	int		ret;

	tmp = ft_itoa_unbase(value, 10, 1);
	ret = (int)ft_strlen(tmp);
	free(tmp);
	if (ret > len_ref)
		return (ret);
	return (len_ref);
}

/*
** ft_max_len calculated for each attribute of the 'l' flag, the max length
** of what will be printed on the terminal.
**
** This allows the information to be properly aligned
*/

t_length	ft_max_len(t_lst *lst, t_length len, char *flag, int *total)
{
	while (lst->elem.name)
	{
		if (!ft_strchr(flag, 'a')
			&& lst->elem.name[0] == '.' && lst->elem.name[1] != '/')
			;
		else
		{
			len.l_link = ft_test_len(lst->elem.link, len.l_link);
			if ((int)ft_strlen(lst->elem.owner_name) > len.l_oname)
				len.l_oname = ft_strlen(lst->elem.owner_name);
			if ((int)ft_strlen(lst->elem.group_name) > len.l_gname)
				len.l_gname = ft_strlen(lst->elem.group_name);
			len.l_size = ft_test_len(lst->elem.size, len.l_size);
			if ((int)ft_strlen(lst->elem.time) > len.l_time)
				len.l_time = ft_strlen(lst->elem.time);
			len.l_minor = ft_test_len(lst->elem.minor, len.l_minor);
			len.l_major = ft_test_len(lst->elem.major, len.l_major);
			*total = *total + lst->elem.blocks;
		}
		lst = lst->nxt;
	}
	return (len);
}
