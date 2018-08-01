/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:30:55 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:22:11 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_ls.h"

void	ft_free_elem(t_tab_dir elem)
{
	free(elem.name);
	free(elem.path);
	free(elem.rights);
	free(elem.owner_name);
	free(elem.group_name);
	free(elem.time);
}
