/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:44:22 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/04 14:50:08 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

char		*ft_strjoin(char const *s1, char const *s2, int i)
{
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = (char*)malloc((ft_strlen(s1)
		+ ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	else
	{
		new = ft_strcpy(new, (char*)s1);
		new = ft_strcat((char*)new, (char*)s2);
		if (i == 1 || i == 3)
		{
			free((char*)s1);
			s1 = NULL;
		}
		if (i == 2 || i == 3)
		{
			free((char *)s2);
			s2 = NULL;
		}
		return (new);
	}
}
