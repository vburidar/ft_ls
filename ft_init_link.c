/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:20:37 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:22:47 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** called in : ft_inittabdir
** initializes the values of the lst elements to NULL
*/

t_lst	*ft_init_link(t_lst *lst)
{
	lst->nxt = NULL;
	lst->elem.dir = NULL;
	lst->elem.path = NULL;
	lst->elem.name = NULL;
	lst->elem.rights = NULL;
	lst->elem.owner_name = NULL;
	lst->elem.group_name = NULL;
	lst->elem.time = NULL;
	return (lst);
}
