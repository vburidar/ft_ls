/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_strsub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:17:21 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/26 21:20:17 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_secure_strsub(char *s, int start, int compteur)
{
	char *del;

	del = s;
	s = ft_strsub(s, start, compteur);
	free(del);
	return (s);
}
