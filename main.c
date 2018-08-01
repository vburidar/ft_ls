/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:05:21 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:12:27 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include "ft_ls.h"
#include "ft_printf.h"

/*
** If ft_ls is called with arguments, ft_check arg will get the different
** arguments stored in lst and print their attributes according to the flags
** and if these attributes are directory or files
*/

void	ft_check_arg(t_lst *lst, char *flag)
{
	DIR	*directory;

	ft_print_lst(lst, flag, 0);
	while (lst->elem.name)
	{
		if (lst->elem.rights[0] == 'd')
		{
			if (lst->previous != NULL || lst->nxt->elem.name)
				ft_printf("\n%s:\n", lst->elem.name);
			{
				directory = opendir(lst->elem.path);
				ft_print_directory(directory, lst->elem.path, flag);
				if (directory)
					closedir(directory);
			}
		}
		lst = lst->nxt;
	}
}

/*
** If ft_ls is called with no arguments, ft_no_arg will check what is in
** the current directory
** ft_print directory will print what's in "."
*/

int		ft_no_arg(char *flag)
{
	DIR		*directory;
	char	*path;

	directory = opendir(".");
	path = ft_strdup(".");
	ft_print_directory(directory, path, flag);
	closedir(directory);
	free(path);
	free(flag);
	return (0);
}

/*
** In main we get the flags that the user entered
** Then we put the arguments in a chained list in ft_inittabdir
** If there are no flag we got to ft_no arg
** Else we sort the arguments in lst accordingly to the flags
** And we go to ft_check_arg
** Finally we deal with freeing the memory allocated
*/

int		main(int argc, char **argv)
{
	t_lst	*lst;
	char	*flag;
	int		test;

	test = argc;
	flag = ft_get_flag(argv);
	test = ft_inittabdir(argv, &lst, flag);
	if (lst == NULL && test == 0)
		return (ft_no_arg(flag));
	else
	{
		lst = ft_sort_lst(&lst, flag);
		ft_check_arg(lst, flag);
	}
	while (lst->nxt)
	{
		ft_free_elem(lst->elem);
		lst = lst->nxt;
		free(lst->previous);
	}
	free(flag);
	free(lst);
	return (0);
}
