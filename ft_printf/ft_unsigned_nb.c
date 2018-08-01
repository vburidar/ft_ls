/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:05:59 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 15:44:15 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_affiche_o(va_list *pt_ap, char *tab_flag)
{
	unsigned long long	valeur;
	int					len;
	char				*ret;

	valeur = 0;
	if (ft_strchr(tab_flag, 'O'))
		valeur = (va_arg(*pt_ap, unsigned long));
	else
		valeur = ft_size_var(tab_flag, pt_ap);
	if (!(ret = malloc(sizeof(char))))
		exit(1);
	*ret = '\0';
	len = 0;
	while (*tab_flag)
	{
		if (*tab_flag == '#' && *ret == '\0' && !(!tab_flag[-21]
					&& valeur == 0))
			ret = ft_strjoin("0", ret, 2);
		tab_flag++;
	}
	return (ft_strjoin(ret, ft_itoa_unbase(valeur, 8, 1), 3));
}

char	*ft_affiche_u(va_list *pt_ap, char *tab_flag)
{
	unsigned long long	valeur;

	if (tab_flag[-11])
		valeur = (va_arg(*pt_ap, unsigned long));
	else
		valeur = ft_size_var(tab_flag, pt_ap);
	return (ft_itoa_unbase(valeur, 10, 1));
}

char	*ft_affiche_p(va_list *pt_ap, char *tab_flag)
{
	unsigned long long	valeur;
	char				*ret;
	char				*tmp;

	if (!(ret = malloc(sizeof(char))))
		exit(1);
	*ret = '\0';
	valeur = va_arg(*pt_ap, unsigned long long);
	while (*(tab_flag + 1) != '\0')
		tab_flag++;
	if (*tab_flag == 'p')
		ret = ft_strjoin("0x", ret, 2);
	tmp = ret;
	return (ft_strjoin(ret, ft_itoa_unbase(valeur, 16, 1), 3));
}

char	*ft_affiche_x(va_list *pt_ap, char *tab_flag)
{
	unsigned long long	valeur;
	char				*ret;

	if (!(ret = malloc(sizeof(char))))
		exit(1);
	*ret = '\0';
	valeur = ft_size_var(tab_flag, pt_ap);
	if (tab_flag[-25 + 9] && tab_flag[-25 + 16] && valeur != 0)
		ret = ft_strjoin(ret, "0x", 1);
	else if (tab_flag[-25 + 9] && tab_flag[-25 + 17] && valeur != 0)
		ret = ft_strjoin(ret, "0X", 1);
	if (tab_flag[-25 + 16])
		return (ft_strjoin(ret, ft_itoa_unbase(valeur, 16, 1), 3));
	else
		return (ft_strjoin(ret, ft_itoa_unbase(valeur, 16, 2), 3));
}

char	*ft_affiche_b(va_list *pt_ap, char *tab_flag)
{
	unsigned long long	valeur;

	valeur = ft_size_var(tab_flag, pt_ap);
	return (ft_itoa_unbase(valeur, 2, 1));
}
