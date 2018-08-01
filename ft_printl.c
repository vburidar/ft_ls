/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:19:57 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:58:33 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "ft_printf.h"
#include "ft_ls.h"

/*
** ft_print_space and ft_length are tool functions used to
** simplify the printing process
*/

void	ft_print_space(int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		ft_printf(" ");
		i = i + 1;
	}
}

int		ft_length(long value)
{
	char	*tmp;
	int		ret;

	tmp = ft_itoa_unbase(value, 10, 1);
	ret = (int)ft_strlen(tmp);
	free(tmp);
	return (ret);
}

/*
** The printl function is divided in two parts in order for the functions
** to stay short
**
** In here, we print the rest of the attributes of the file, still using the
** length stored in the t_length structure len.
*/

void	ft_printl_end(t_lst *lst, t_length len)
{
	if (lst->elem.rights[0] == 'b' || lst->elem.rights[0] == 'c')
	{
		ft_print_space(len.l_major - ft_length(lst->elem.major));
		ft_printf("%d, ", lst->elem.major);
		ft_print_space(len.l_minor - ft_length(lst->elem.minor));
		ft_printf("%d ", lst->elem.minor);
	}
	else
	{
		if (len.l_size > len.l_major + len.l_minor + 1)
			ft_print_space(len.l_size - ft_length(lst->elem.size));
		else
			ft_print_space(len.l_major + len.l_minor
				+ 1 - ft_length(lst->elem.size));
		ft_printf(" %d ", lst->elem.size);
	}
	ft_print_space(len.l_time - ft_strlen(lst->elem.time));
	ft_printf("%s %s\n", lst->elem.time, lst->elem.name);
}

/*
** The total is displayed in two cases:
** - 'a' flag is not activated and the directory is not hidden
** - 'a' flag is activated and the directory is hidden
**
** The total must not be printed twice
*/

int		ft_print_total(t_lst *lst, char *flag, int total, int i)
{
	while (lst->elem.name)
	{
		if (lst->elem.rights[0] == 'd' && i == 0)
			;
		else if (lst->elem.name[0] != '.' && !ft_strchr(flag, 'a'))
		{
			ft_printf("total %d\n", total);
			return (1);
		}
		else if (lst->elem.name[0] == '.' && ft_strchr(flag, 'a'))
		{
			ft_printf("total %d\n", total);
			return (1);
		}
		lst = lst->nxt;
	}
	return (0);
}

/*
** ft_printl deals with printing the files' and directories' attributes
** when the 'l' flag is activated
**
** In order for the attributes to be properly aligned on the terminal
** for all the files a structure t_length calculate the max size of each
** attribute
**
** Then all the detailed attributes for each file are being displayed
** using this length.
*/

void	ft_printl(t_lst *lst, char *flag, int input)
{
	t_length	len;
	int			total;

	total = 0;
	ft_init_len(&len);
	len = ft_max_len(lst, len, flag, &total);
	ft_print_total(lst, flag, total, input);
	while (lst->elem.name)
	{
		if (lst->elem.rights[0] == 'd' && input != 1)
			;
		else if ((lst->elem.name[0] != '.' || (lst->elem.name[0] == '.'
			&& (ft_strchr(flag, 'a') || lst->elem.name[1] == '/')))
			|| (lst->elem.name[0] == '.' && lst->elem.name[1] == '.'
			&& lst->elem.name[2] == '/'))
		{
			ft_printf("%s  ", lst->elem.rights);
			ft_print_space(len.l_link - ft_length(lst->elem.link));
			ft_printf("%d %s ", lst->elem.link, lst->elem.owner_name);
			ft_print_space(len.l_oname - ft_strlen(lst->elem.owner_name));
			ft_printf("%s ", lst->elem.group_name);
			ft_print_space(len.l_gname - ft_strlen(lst->elem.group_name));
			ft_printl_end(lst, len);
		}
		lst = lst->nxt;
	}
}
