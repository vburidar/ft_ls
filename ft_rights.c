/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:09:56 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:53:42 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/*
** ft_rights and ft_find_rights get the rights attached to a file and
** and store them in a char* string
**
** It will used in case the 'l' flag is active
*/

char		*ft_find_right(char right, char *ret, int i)
{
	if (right - '4' >= 0)
	{
		ret[3 * i + 1] = 'r';
		right = right - 4;
	}
	if (right - '2' >= 0)
	{
		ret[3 * i + 2] = 'w';
		right = right - 2;
	}
	if (right - '1' >= 0)
	{
		ret[3 * i + 3] = 'x';
		right = right - 1;
	}
	return (ret);
}

char		*ft_rights(char *rights)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	if (!(ret = malloc(11 * sizeof(char))))
		exit(1);
	while (i < 11)
	{
		ret[i] = '-';
		i = i + 1;
	}
	i = 0;
	tmp = rights + ft_strlen(rights) - 3;
	while (i < 3)
	{
		ret = ft_find_right(tmp[i], ret, i);
		i = i + 1;
	}
	ret[10] = '\0';
	return (ret);
}

/*
** ft_find_type and ft_type get the type of the file and store it in the
** first char of the "rights" string in the "file" element of the list of files
** It also modify the name of the file if it is a symbolic link (and if the 'l'
** flag is active)
*/

char		ft_find_type(mode_t st_mode)
{
	if (S_ISSOCK(st_mode))
		return ('s');
	if (S_ISDIR(st_mode))
		return ('d');
	if (S_ISBLK(st_mode))
		return ('b');
	if (S_ISCHR(st_mode))
		return ('c');
	if (S_ISFIFO(st_mode))
		return ('p');
	return ('-');
}

t_tab_dir	ft_type(t_tab_dir file, mode_t st_mode, char *path, char *flag)
{
	char	buf[128];
	char	*tmp;
	int		error;

	buf[127] = '\0';
	file.rights[0] = ft_find_type(st_mode);
	if ((error = readlink(path, buf, 127)) > 0)
	{
		tmp = ft_strsub(buf, 0, error);
		file.rights[0] = 'l';
		if (ft_strchr(flag, 'l'))
		{
			file.name = ft_strjoin(file.name, " -> ", 1);
			file.name = ft_strjoin(file.name, tmp, 3);
			tmp = NULL;
		}
		if (tmp)
			free(tmp);
	}
	return (file);
}
