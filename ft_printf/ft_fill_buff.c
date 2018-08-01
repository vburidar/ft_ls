/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:59:29 by vburidar          #+#    #+#             */
/*   Updated: 2017/12/26 19:45:22 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_fill_buff(const char *adr)
{
	char	tmp[32];
	int		i;

	i = 0;
	while (*adr && *adr != '%' && i < 32)
	{
		tmp[i] = *adr;
		i = i + 1;
		adr = adr + 1;
	}
	write(1, tmp, i);
	return (i - 1);
}
