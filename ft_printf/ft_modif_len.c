/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:48:09 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 14:43:35 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int					ft_find_double(char *tab_flag, char c)
{
	while (*tab_flag)
	{
		if (*tab_flag == c && *(tab_flag + 1) == c)
		{
			*tab_flag = ',';
			*(tab_flag + 1) = ',';
			return (1);
		}
		tab_flag++;
	}
	return (0);
}

int					ft_find_single(char *tab_flag, char c)
{
	while (*tab_flag)
	{
		if (*tab_flag == c)
			return (1);
		tab_flag++;
	}
	return (0);
}

unsigned long long	ft_size_var(char *tab_flag, va_list *pt_ap)
{
	unsigned long long valeur;

	if (ft_find_double(tab_flag, 'l'))
		valeur = (va_arg(*pt_ap, unsigned long long));
	else if (ft_find_single(tab_flag, 'l'))
		valeur = (va_arg(*pt_ap, unsigned long));
	else if (ft_find_single(tab_flag, 'j'))
		valeur = (va_arg(*pt_ap, uintmax_t));
	else if (ft_find_single(tab_flag, 'z'))
		valeur = (va_arg(*pt_ap, size_t));
	else if (ft_find_double(tab_flag, 'h'))
		valeur = (unsigned char)(va_arg(*pt_ap, int));
	else if (ft_find_single(tab_flag, 'h'))
		valeur = (unsigned short)(va_arg(*pt_ap, int));
	else
		valeur = (va_arg(*pt_ap, unsigned int));
	return (valeur);
}
