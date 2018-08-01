/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:08:47 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:53:20 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_ls.h"

static t_lst	*ft_search_begin(t_lst *lst, t_lst *curseur)
{
	if (lst->nxt->elem.name && lst->elem.val_time < lst->nxt->elem.val_time)
	{
		curseur = lst->nxt;
		while (curseur->elem.name
				&& lst->elem.val_time < curseur->elem.val_time)
			curseur = curseur->nxt;
		return (curseur);
	}
	return (lst);
}

static t_lst	*ft_search_end(t_lst *lst, t_lst *curseur)
{
	if (lst->previous && lst->previous->elem.val_time < lst->elem.val_time)
	{
		curseur = lst->previous;
		while (curseur->previous && curseur->elem.val_time < lst->elem.val_time)
			curseur = curseur->previous;
		return (curseur->nxt);
	}
	return (lst);
}

t_lst			*ft_insert_link(t_lst *start, t_lst *target, int i)
{
	if (start->previous)
		start->previous->nxt = start->nxt;
	if (start->nxt)
		start->nxt->previous = start->previous;
	start->previous = target->previous;
	start->nxt = target;
	if (target->previous)
		target->previous = start;
	if (start->previous)
		start->previous->nxt = start;
	if (i == 1)
	{
		while (start->previous)
			start = start->previous;
	}
	else
	{
		while (start->nxt)
			start = start->nxt;
	}
	return (start);
}

t_lst			*ft_sort_time(t_lst *lst)
{
	t_lst			*curseur;
	t_lst			*init;
	t_lst			*end;

	curseur = lst;
	init = lst;
	end = lst;
	while (end->nxt->elem.name)
		end = end->nxt;
	while (lst != end->previous && lst->nxt != end->previous && lst != end)
	{
		curseur = ft_search_begin(lst, curseur);
		if (curseur != lst)
			lst = ft_insert_link(lst, curseur, 1);
		else
			lst = lst->nxt;
		curseur = ft_search_end(end, curseur);
		if (curseur != end)
			end = ft_insert_link(end, curseur, 0);
		end = end->previous;
	}
	while (init->previous)
		init = init->previous;
	return (init);
}
