/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:25:59 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:57:07 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

/*
** ft_nexto swaps two items of a double-linked list in the special case
** when the two items are next to one another
*/

void	ft_nexto(t_lst *elem1, t_lst *elem2)
{
	elem1->nxt = elem2->nxt;
	elem2->nxt = elem1;
	elem2->previous = elem1->previous;
	elem1->previous = elem2;
}

/*
** ft_swap_lst swaps two items of a double-linked list
*/

t_lst	*ft_swap_lst(t_lst *elem1, t_lst *elem2)
{
	t_lst	*tmp;

	if (elem1->previous)
		elem1->previous->nxt = elem2;
	if (elem2->nxt)
		elem2->nxt->previous = elem1;
	if (!(tmp = malloc(sizeof(t_lst))))
		exit(1);
	tmp->nxt = elem2->nxt;
	tmp->previous = elem2->previous;
	if (elem1->nxt != elem2)
	{
		elem1->nxt->previous = elem2;
		elem2->previous->nxt = elem1;
		elem2->nxt = elem1->nxt;
		elem2->previous = elem1->previous;
		elem1->nxt = tmp->nxt;
		elem1->previous = tmp->previous;
	}
	else
		ft_nexto(elem1, elem2);
	free(tmp);
	return (elem2);
}
