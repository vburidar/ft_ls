/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:50:15 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 09:06:21 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "ft_ls.h"
#include "ft_printf.h"

/*
** ft_arg_is_flag tells if the argument entered by the user
** is a flag or not
*/

int		ft_arg_is_flag(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] != '\0')
		i = i + 1;
	return (i);
}

/*
** ft_create_link specificially allocates memory for each
** link in the lst list and for what it contains.
**
** Details about the files/directories are obtained in
** ft_get_l. They will be used in the case the 'l' flag
** is activated
*/

t_lst	**ft_create_link(t_lst **lst, char *arg, char *flag)
{
	t_lst		*new;
	struct stat	buf;

	if (lstat(arg, &buf) == 0)
	{
		(*lst)->elem.name = ft_strdup(arg);
		(*lst)->elem.path = ft_strdup(arg);
		(*lst)->elem = ft_get_l(buf, arg, (*lst)->elem, flag);
		if (!(new = malloc(sizeof(t_lst))))
			exit(1);
		ft_init_link(new);
		(*lst)->nxt = new;
		new->previous = *lst;
		(*lst) = (*lst)->nxt;
	}
	else
		ft_printf("ft_ls: %s: %s\n", arg, strerror(errno));
	return (lst);
}

/*
** ft_inittabdir initializes the list of files and directory that
** will be looked into according to the arguments that are inputed
** by the user
*/

int		ft_inittabdir(char **argv, t_lst **lst, char *flag)
{
	t_lst		*init;
	int			i;

	if (!(*lst = malloc(sizeof(t_lst))))
		exit(1);
	ft_init_link((*lst));
	(*lst)->previous = NULL;
	init = *lst;
	i = ft_arg_is_flag(argv);
	if (argv[i] == NULL)
	{
		free(*lst);
		*lst = NULL;
		return (0);
	}
	while (argv[i])
	{
		lst = ft_create_link(lst, argv[i], flag);
		i++;
	}
	(*lst)->nxt = NULL;
	(*lst)->elem.name = NULL;
	(*lst) = init;
	return (1);
}
