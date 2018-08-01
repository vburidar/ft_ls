/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 09:54:35 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 09:25:46 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "ft_ls.h"
#include "ft_printf.h"

/*
** ft_init_address initializes values of the new elements of the list
** adds it at the end of the list and returns a pointer on that item
*/

t_lst	*ft_init_addr(t_lst *new, t_lst *r)
{
	new->previous = r;
	new->elem.name = NULL;
	r->nxt = new;
	new->nxt = NULL;
	r = r->nxt;
	return (r);
}

/*
** ft_init_path creates the path of a given item in the list
*/

char	*ft_init_path(const char *path, t_lst *lst)
{
	char *ret;

	ret = NULL;
	if (path[0] == '.' || path[0] == '/')
		lst->elem.path = ft_strdup(path);
	else
		lst->elem.path = ft_strjoin(path, "/", 0);
	ret = ft_strjoin(lst->elem.path, "/", 0);
	ret = ft_strjoin(ret, lst->elem.name, 1);
	return (ret);
}

t_lst	*ft_null(t_lst *lst)
{
	free(lst->elem.name);
	free(lst->elem.path);
	lst->elem.path = NULL;
	lst->elem.name = NULL;
	lst->nxt = NULL;
	return (lst);
}

/*
** ft_cpdir creates a new item that is added to the list
** the item contains the details given by ft_get_l.
*/

t_lst	*ft_cpdir(t_lst *r, struct dirent *tmp, const char *path, char *flag)
{
	struct stat	buf;
	char		*str;
	t_lst		*new;

	ft_init_link(r);
	r->elem.name = ft_strjoin(tmp->d_name, "\0", 0);
	r->elem.file = tmp->d_type;
	str = ft_init_path(path, r);
	if ((lstat(str, &buf)) == 0)
	{
		r->elem = ft_get_l(buf, str, r->elem, flag);
		if (!(new = malloc(sizeof(t_lst))))
			exit(1);
		r = ft_init_addr(new, r);
	}
	else
		r = ft_null(r);
	free(str);
	return (r);
}

/*
** Given a path, a directory and the flags, ft_create_lst will read
** what is inside that directory and create and return a list of element 
** detailing the attributes of the files and directory stored in the 
** given directory.
*/

t_lst	*ft_create_lst(DIR *directory, const char *path, char *flag)
{
	struct dirent	*tmp;
	t_lst			*r;

	if (!(r = malloc(sizeof(t_lst))))
		exit(1);
	r->previous = NULL;
	while ((tmp = readdir(directory)))
		r = ft_cpdir(r, tmp, path, flag);
	while (r->previous)
		r = r->previous;
	return (r);
}
