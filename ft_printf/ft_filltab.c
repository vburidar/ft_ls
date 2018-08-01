/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filltab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:01:06 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 13:56:39 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_finish_filltab(char tab[128])
{
	tab['o'] = 22;
	tab['s'] = 23;
	tab['S'] = 24;
	tab['b'] = 25;
	tab['-'] = 1;
	tab[' '] = 2;
	tab['+'] = 3;
	tab['.'] = 4;
	tab['h'] = 5;
	tab['l'] = 6;
	tab['j'] = 7;
}

void		ft_filltab(char tab[128])
{
	int	c;

	c = '0';
	ft_bzero(tab, 128);
	tab['d'] = 10;
	tab['D'] = 11;
	tab['i'] = 12;
	tab['u'] = 13;
	tab['U'] = 14;
	tab['p'] = 15;
	tab['x'] = 16;
	tab['X'] = 17;
	tab['%'] = 18;
	tab['c'] = 19;
	tab['C'] = 20;
	tab['O'] = 21;
	tab['z'] = 8;
	tab['#'] = 9;
	ft_finish_filltab(tab);
	while (c <= '9')
	{
		tab[c] = 1;
		c++;
	}
}
