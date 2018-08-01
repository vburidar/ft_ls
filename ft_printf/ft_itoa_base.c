/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:18:15 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/06 11:17:27 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

char	*ft_itoa_dec(long long n)
{
	unsigned long long	tmp;
	char				nbr[12];
	int					i;

	i = 10;
	ft_bzero(nbr, 12);
	if (n < 0)
		tmp = (unsigned long long)(-n);
	else
		tmp = n;
	while (tmp != 0)
	{
		nbr[i] = tmp % 10 + '0';
		tmp = tmp / 10;
		i = i - 1;
	}
	if (nbr[10] == '\0')
	{
		nbr[10] = '0';
		return (ft_strdup(nbr + 10));
	}
	if (n >= 0)
		return (ft_strdup(nbr + i + 1));
	return (ft_strjoin("-", nbr + i + 1, 0));
}

char	*ft_itoa_unbase(unsigned long long n, int base, int i)
{
	unsigned long long	tmp;
	char				nbr[20];
	char				tab[17];
	int					j;

	j = 18;
	ft_bzero(nbr, 20);
	if (i == 1)
		ft_strcpy(tab, "0123456789abcdef");
	if (i == 2)
		ft_strcpy(tab, "0123456789ABCDEF");
	tmp = n;
	while (tmp != 0)
	{
		nbr[j] = tab[tmp % base];
		tmp = tmp / base;
		j = j - 1;
	}
	if (nbr[18] == '\0')
	{
		nbr[18] = '0';
		nbr[19] = '\0';
		return (ft_strdup(nbr + 18));
	}
	return (ft_strdup(nbr + j + 1));
}
