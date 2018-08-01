/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:48:02 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 15:43:03 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

char		*ft_dot(char *str, char *tab_flag, char conv)
{
	unsigned int	compteur;
	char			*tmp;

	tmp = tab_flag;
	if (tmp[-21])
	{
		tab_flag = ft_strchr(tab_flag, '.');
		compteur = ft_find_nb(tab_flag + 1);
		if (compteur == 0 && ft_zero(str) == 0 && conv != '%')
			ft_replace(str, '0', ' ', tmp);
		if (*str == '\0')
			return (str);
		if (conv == 'c' && *str == 'a' && *(str + 2) == '1')
			return (str);
		if (tmp[-22] || tmp[-23] || (ft_strchr(str, '-') && conv == 'd'))
			compteur = compteur + 1;
		if (conv == 'p' || (ft_strchr(tmp, '#') && conv == 'x'))
			compteur = compteur + 2;
		if (!(tmp[-7]) && !(tmp[-2]) && !(tmp[-6])
				&& !(tmp[-5]) && !(tmp[-1]))
			str = ft_concat(str, compteur, '0', *tab_flag);
	}
	return (str);
}

static char	*ft_flag_z_min(char **tab_flag, char conv, char *str, char *tmp)
{
	unsigned int	compteur;

	compteur = ft_zero(*(tab_flag));
	if (ft_strchr(tmp, '0') && ft_strchr(tmp, '-'))
		**tab_flag = '-';
	if (**tab_flag == '0' && (ft_strchr(tmp, '.') && (conv != 'c'
		&& conv != 's' && conv != 'S' && conv != 'C' && conv != '%')))
		str = ft_concat(str, compteur, ' ', **tab_flag);
	else
		str = ft_concat(str, compteur, '0', **tab_flag);
	*tab_flag = *tab_flag + 1;
	while (**tab_flag >= '0' && **tab_flag <= '9')
		*tab_flag = *tab_flag + 1;
	return (str);
}

char		*ft_precision(char *str, char *tab_flag, char conv)
{
	char			*tmp;
	unsigned int	compteur;

	tmp = tab_flag;
	str = ft_dot(str, tab_flag, conv);
	while (*tab_flag != '\0')
	{
		if ((*tab_flag == '0' || *tab_flag == '-'))
			str = ft_flag_z_min(&tab_flag, conv, str, tmp);
		else if (*tab_flag == '.')
		{
			tab_flag++;
			while (*tab_flag >= '0' && *tab_flag <= '9')
				tab_flag++;
		}
		else if (*tab_flag >= '1' && *tab_flag <= '9')
		{
			compteur = ft_find_nb(tab_flag);
			str = ft_concat(str, compteur, ' ', *tab_flag);
			tab_flag++;
		}
		else
			tab_flag++;
	}
	return (str);
}
