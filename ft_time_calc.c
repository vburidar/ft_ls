/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:31:06 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 09:02:13 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_ls.h"

/*
** ft_time_calc creates a string with the time information about the file
** Format Month/Day/(Hour or Year) (see below)
** Two cases
** - The file is less than 6 months old. The hour is stored
** - The file is older than 6 months. The year is stored
*/

char	*ft_time_calc(const time_t *time_val)
{
	char	*ret;
	char	*tmp;

	if (time(NULL) - *time_val > 60 * 60 * 24 * 183
		|| time(NULL) - *time_val < -3600)
	{
		ret = ft_strsub(ctime(time_val), 4, 6);
		ret = ft_strjoin(ret, " ", 1);
		ret = ft_strjoin(ret, ctime(time_val) + 19, 1);
		tmp = ret;
		ret = ft_strsub(ret, 0, 12);
		free(tmp);
		return (ret);
	}
	else
		return (ft_strsub(ctime(time_val), 4, 12));
}
