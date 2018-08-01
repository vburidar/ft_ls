/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:06:52 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:51:43 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_ls.h"

/*
** ft_search_best searches search the "smallest string" according
** to ASCII sorting
*/

static t_lst	*ft_search_best(t_lst *curseur, char *ref)
{
	t_lst	*best;

	best = NULL;
	while (curseur && curseur->elem.name)
	{
		if (ft_strcmp(curseur->elem.name, ref) < 0)
		{
			best = curseur;
			ref = curseur->elem.name;
		}
		curseur = curseur->nxt;
	}
	return (best);
}

/*
** Ft_sort_directory uses selection sorting to sort the directory
*/

t_lst			*ft_sort_directory(t_lst *lst)
{
	char	*ref;
	t_lst	*best;
	t_lst	*curseur;
	t_lst	*init;
	int		i;

	i = 0;
	curseur = lst;
	init = lst;
	while (lst->nxt)
	{
		curseur = lst;
		ref = lst->elem.name;
		best = ft_search_best(curseur, ref);
		if (best)
			lst = ft_swap_lst(lst, best);
		lst = lst->nxt;
	}
	while (init->previous)
		init = init->previous;
	return (init);
}

t_lst			*ft_alloc(void)
{
	t_lst	*lst;

	if (!(lst = malloc(sizeof(t_lst))))
		exit(1);
	return (lst);
}

/*
** ft_reverse each link of the "lst" list.
**
** lst is a doubled-linked list (forward and backward). This allows
** to revert the sorting quite easily by reversing each link one after
** the other, going through "lst" only once.
*/

t_lst			*ft_reverse(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*init;

	init = ft_alloc();
	init->nxt = NULL;
	init->elem.name = NULL;
	while (lst->elem.name)
	{
		tmp = lst->nxt;
		lst->nxt = lst->previous;
		if (lst->nxt == NULL)
		{
			lst->nxt = init;
			init->previous = lst;
		}
		lst->previous = tmp;
		if (lst->previous->elem.name == NULL)
		{
			free(lst->previous);
			lst->previous = NULL;
			return (lst);
		}
		lst = lst->previous;
	}
	return (lst);
}

/*
** ft_sort_lst sends the lst to a sorting function according to the flag used
**- no flag: ASCII sorting
**- t flag : time sorting
**- r flag : reversed ASCII sorting
*/

t_lst			*ft_sort_lst(t_lst **lst, char *flag)
{
	if ((*lst)->nxt == NULL)
		return (*lst);
	if ((*lst)->nxt->elem.name == NULL)
		return (*lst);
	*lst = ft_sort_directory(*lst);
	if (ft_strchr(flag, 't'))
		*lst = ft_sort_time(*lst);
	if (ft_strchr(flag, 'r'))
		*lst = ft_reverse(*lst);
	return (*lst);
}
