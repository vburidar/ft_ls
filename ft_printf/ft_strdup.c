/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:41:04 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/06 11:13:55 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

char		*ft_strdup(const char *s)
{
	int		i;
	char	*new_str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((new_str = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		while (s[i])
		{
			new_str[i] = s[i];
			i = i + 1;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	else
		exit(1);
}
