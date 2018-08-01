/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:51:37 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 14:53:39 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

static int	affiche_str(char *str, char *tab_flag, char conv)
{
	static int	test;
	int			len;

	test = 0;
	if ((conv == 'c' || conv == 'C') && str[0] == 'a' && str[2] == '1')
		test = 1;
	str = ft_precision(str, tab_flag, conv);
	if (test == 1)
		*ft_strchr(str, 'a') = '\0';
	if (str != NULL)
		tab_flag = str;
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	if (test == 1)
	{
		ft_putchar('\0');
		str = str + len + 1;
		write(1, str, ft_strlen(str));
		len = len + 1 + ft_strlen(str);
	}
	free(tab_flag);
	return (len);
}

static void	ft_init_tabf(t_tabf tabf[16])
{
	tabf[0].pt_affiche = ft_affiche_d;
	tabf[1].pt_affiche = ft_affiche_d;
	tabf[2].pt_affiche = ft_affiche_d;
	(tabf[3]).pt_affiche = ft_affiche_u;
	(tabf[4]).pt_affiche = ft_affiche_u;
	(tabf[5]).pt_affiche = ft_affiche_p;
	(tabf[6]).pt_affiche = ft_affiche_x;
	(tabf[7]).pt_affiche = ft_affiche_x;
	(tabf[8]).pt_affiche = ft_affiche_per;
	(tabf[9]).pt_affiche = ft_affiche_c;
	(tabf[10]).pt_affiche = ft_affiche_c;
	(tabf[11]).pt_affiche = ft_affiche_o;
	(tabf[12]).pt_affiche = ft_affiche_o;
	(tabf[13]).pt_affiche = ft_affiche_s;
	(tabf[14]).pt_affiche = ft_affiche_s;
	(tabf[15]).pt_affiche = ft_affiche_b;
	ft_filltab(tabf[0].tab);
}

static int	ft_notvalidstr(char *tab_flag, t_len *len, int ret, char *format)
{
	char		*tmp2;

	if (ret == 0)
	{
		if (!(tmp2 = malloc(2 * sizeof(char))))
			exit(1);
		tmp2[0] = '\0';
		if (ft_strlen(tab_flag) > 0)
			tmp2[0] = *format;
		tmp2[1] = '\0';
		if (*tab_flag == '\0')
			len->len_flag = len->len_flag - 1;
		ret = affiche_str(tmp2, tab_flag, 's');
		return (ret);
	}
	return (1);
}

static int	ft_flag(const char *format,
		va_list *pt_ap, t_len *len, t_tabf *tabf)
{
	int			ret;
	int			tmp;
	char		compteur;
	char		*tab_flag;

	tab_flag = tabf[1].tab + 25;
	ft_bzero(tabf[1].tab, 32);
	compteur = 0;
	while (*format && (ret = tabf->tab[(int)*format]))
	{
		ft_add((char)*format, tabf[1].tab);
		tabf[1].tab[(int)tabf[0].tab[(int)*format]] = 1;
		if (tabf->tab[(int)*format] > 9)
		{
			tmp = tabf->tab[(int)*format] - 10;
			ret = affiche_str((tabf[tmp].pt_affiche)(pt_ap, tab_flag),
					tab_flag, tabf[1].tab[compteur + 25]);
			return (ret);
		}
		len->len_flag = len->len_flag + 1;
		format = format + 1;
		compteur = compteur + 1;
	}
	return (ft_notvalidstr(tab_flag, len, ret, (char*)format));
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*init;
	t_len		len;
	t_tabf		tabf[15];

	va_start(ap, format);
	init = format;
	len.len_str = 0;
	ft_init_tabf(tabf);
	while (*format)
	{
		if (*format != '%')
			format = format + ft_fill_buff(format);
		else if (*format == '%')
		{
			len.len_flag = 2;
			len.len_str = len.len_str +
				ft_flag((format + 1), &ap, &len, tabf) - len.len_flag;
			format = format + len.len_flag - 1;
		}
		if (*format)
			format = format + 1;
	}
	va_end(ap);
	return (format - init + len.len_str);
}
