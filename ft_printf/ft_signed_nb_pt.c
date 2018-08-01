/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_nb_pt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:56:14 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 15:44:39 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_affiche_d(va_list *pt_ap, char *tab_flag)
{
	long long	valeur;
	char		*ret;

	if (ft_find_double(tab_flag, 'l'))
		valeur = (long long)(va_arg(*pt_ap, long long int));
	else if (ft_find_single(tab_flag, 'l'))
		valeur = (long long)(va_arg(*pt_ap, long int));
	else if (ft_find_single(tab_flag, 'j'))
		valeur = (long long)(va_arg(*pt_ap, intmax_t));
	else if (ft_find_single(tab_flag, 'z'))
		valeur = (long long)(va_arg(*pt_ap, size_t));
	else if (ft_strchr(tab_flag, 'D'))
		valeur = va_arg(*pt_ap, long);
	else if (ft_find_double(tab_flag, 'h'))
		valeur = (char)(va_arg(*pt_ap, int));
	else if (ft_find_single(tab_flag, 'h'))
		valeur = (short int)(va_arg(*pt_ap, int));
	else
		valeur = (va_arg(*pt_ap, int));
	ret = ft_itoa_dec(valeur);
	ret = ft_plus_space(ret, tab_flag, valeur);
	return (ret);
}

char	*ft_affiche_per(va_list *pt_ap, char *tab_flag)
{
	va_list		*tmp;
	char		*ret;

	tmp = pt_ap;
	ret = tab_flag;
	if (!(ret = malloc(2 * (sizeof(char)))))
		exit(1);
	ret[0] = '%';
	ret[1] = '\0';
	return (ret);
}
