/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:33:27 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/14 17:05:06 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char*)(malloc((len + 1) * sizeof(char)))))
		return (NULL);
	else
	{
		while (i < len)
		{
			new[i] = s[i + start];
			i = i + 1;
		}
		new[i] = '\0';
		return (new);
	}
}
