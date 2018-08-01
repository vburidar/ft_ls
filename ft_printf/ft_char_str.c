/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:24:34 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 15:49:53 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include "ft_printf.h"

static char	*ft_create_ms(va_list *pt_ap)
{
	wchar_t	*ms;
	char	*s;
	char	*tmp;

	ms = va_arg(*pt_ap, wchar_t*);
	if (ms == NULL)
		s = NULL;
	else
		s = ft_strdup("");
	while (ms != NULL && (tmp = ft_getwchar(*ms)) && *tmp)
	{
		s = ft_strjoin(s, tmp, 3);
		ms = ms + 1;
	}
	if (ms != NULL)
		free(tmp);
	return (s);
}

char		*ft_affiche_s(va_list *pt_ap, char *tab_flag)
{
	char	*s;
	int		compteur;

	compteur = -1;
	if (tab_flag[-25 + 23] && !tab_flag[-25 + 6])
		s = ft_strdup(va_arg(*pt_ap, char*));
	else
		s = ft_create_ms(pt_ap);
	if (s == NULL)
	{
		free(s);
		s = ft_strdup("(null)");
	}
	while (*tab_flag)
	{
		if (*tab_flag == '.')
			compteur = ft_find_nb(tab_flag + 1);
		tab_flag++;
	}
	if (compteur < (int)(ft_strlen(s)) && compteur >= 0)
		s = ft_secure_strsub(s, 0, compteur);
	return (s);
}

char		*ft_affiche_c(va_list *pt_ap, char *tab_flag)
{
	char	*s;
	int		val_char;

	if (!(s = malloc(3 * sizeof(char))))
		exit(1);
	s[0] = '1';
	s[1] = '\0';
	s[2] = '\0';
	val_char = (wchar_t)(va_arg(*pt_ap, int));
	if ((ft_strchr(tab_flag, 'C') || ft_strchr(tab_flag, 'l')) && val_char != 0)
	{
		free(s);
		s = ft_getwchar((wchar_t)(val_char));
	}
	else
		s[0] = (char)(val_char);
	if (s[0] == '\0')
	{
		s[0] = 'a';
		s[2] = '1';
	}
	return (s);
}
