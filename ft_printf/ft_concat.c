/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:26:41 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/27 15:46:28 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*ft_firstcar(char *str, char **first, char d, char flag)
{
	if (!(*first = malloc(2 * sizeof(char))))
		exit(1);
	**first = '\0';
	*(*first + 1) = '\0';
	if (((*str == ' ' || ((*str == '+' || *str == '-') && d == '0'))
		&& flag != '-') || (d == '0' && *str == '0'
		&& (*(str + 1) == 'x' || *(str + 1) == 'X')))
	{
		**first = *str;
		*str = d;
		if (d == '0' && *str == '0'
			&& (*(str + 1) == 'x' || *(str + 1) == 'X'))
		{
			*(*first + 1) = *(str + 1);
			*(str + 1) = d;
		}
	}
	return (str);
}

static char	*ft_inittmp(char *tmp, int compteur, char d)
{
	int i;

	i = 0;
	if (!(tmp = (char*)malloc((compteur + 1) * sizeof(char))))
		exit(1);
	while (i < compteur)
	{
		tmp[i] = d;
		i = i + 1;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*ft_cpstr(char *str, char flag, char *tmp, int compteur)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (flag == '-')
			tmp[i] = str[i];
		else
			tmp[compteur - ft_strlen(str) + i] = str[i];
		i = i + 1;
	}
	return (tmp);
}

char		*ft_concat(char *str, unsigned int compteur, char d, char flag)
{
	char	*first;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (flag == '-')
		d = ' ';
	if (compteur > ft_strlen(str))
	{
		str = ft_firstcar(str, &first, d, flag);
		tmp = ft_inittmp(tmp, compteur, d);
		tmp = ft_cpstr(str, flag, tmp, compteur);
		if (*first != '\0')
			*tmp = *first;
		if (*(first + 1) != '\0')
			*(tmp + 1) = *(first + 1);
	}
	else
		return (str);
	free(first);
	free(str);
	return (tmp);
}
