/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:49:45 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:22:22 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"
#include "ft_printf.h"

/*
** ft_valid_flag checks if the flags are valid and print the
** usage message if not
*/

static void	ft_valid_flag(char *flag)
{
	char	*valid_flag;
	int		i;

	i = 0;
	valid_flag = ft_strdup("lRart");
	while (flag[i])
	{
		if (!ft_strchr(valid_flag, flag[i]))
		{
			ft_printf("ft_ls: illegal option -- %c\n");
			ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
			exit(1);
		}
		i = i + 1;
	}
	free(valid_flag);
}

/*
** ft_get_flag put all the different flags in a single string
*/

char		*ft_get_flag(char **argv)
{
	char	*flag;
	int		i;

	if (!(flag = malloc(sizeof(char))))
		exit(1);
	*flag = '\0';
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		flag = ft_strjoin(flag, argv[i] + 1, 1);
		i = i + 1;
	}
	ft_valid_flag(flag);
	return (flag);
}
