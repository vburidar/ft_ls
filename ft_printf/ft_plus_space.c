/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:12:54 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 15:46:14 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_plus_space(char *ret, char *tab_flag, int valeur)
{
	char	*tmp;
	int		test;

	test = 0;
	tmp = tab_flag;
	while (*tab_flag)
	{
		if (*tab_flag == '+' && valeur >= 0 && test == 0)
		{
			ret = ft_strjoin("+", ret, 2);
			test = 1;
		}
		tab_flag++;
	}
	tab_flag = tmp;
	while (*tab_flag)
	{
		if (*tab_flag == ' ' && valeur >= 0 && test == 0)
		{
			ret = ft_strjoin(" ", ret, 2);
			test = 1;
		}
		tab_flag++;
	}
	return (ret);
}
