/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:05:59 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 09:07:01 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "ft_printf.h"
#include "ft_ls.h"

/*
** ft_name and ft_grp_name get the name and group name attached
** to the file
*/

char		*ft_name(uid_t st_uid)
{
	struct passwd	*tmp;

	tmp = getpwuid(st_uid);
	if (tmp == NULL)
		return (ft_itoa_unbase(st_uid, 10, 1));
	return (ft_strdup(tmp->pw_name));
}

char		*ft_grp_name(gid_t gr_gid)
{
	struct group	*tmp;

	tmp = getgrgid(gr_gid);
	if (tmp == NULL)
		return (ft_itoa_unbase(gr_gid, 10, 1));
	return (ft_strdup(tmp->gr_name));
}

/*
** ft_special deals with storing details regarding the rights on the file
*/

char		*ft_special(mode_t mode, char *rights)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (rights[i * 3] == 'x' && ((S_ISGID & mode) || (S_ISUID & mode)))
			rights[i * 3] = 's';
		else if ((S_ISGID & mode) || (S_ISUID & mode))
			rights[i * 3] = 's';
		i++;
	}
	if (rights[9] == 'x' && (S_ISVTX & mode))
		rights[9] = 't';
	else if (S_ISVTX & mode)
		rights[9] = 'T';
	return (rights);
}

/*
** ft_get_l fills the lst's attributes "file" with data describing the file
** located at the path "*path" according to the flag "*flag"
**
** the buf stat structures is a structure included in the library <sys/stat>
** that is designed to store data on files.
*/

t_tab_dir	ft_get_l(struct stat buf, char *path, t_tab_dir file, char *flag)
{
	char		*rights;

	rights = ft_itoa_unbase(buf.st_mode, 8, 1);
	file.rights = ft_rights(rights + ft_strlen(rights) - 4);
	file.rights = ft_special(buf.st_mode, file.rights);
	free(rights);
	file = ft_type(file, buf.st_mode, path, flag);
	file.link = buf.st_nlink;
	file.owner_name = ft_name(buf.st_uid);
	file.group_name = ft_grp_name(buf.st_gid);
	file.size = buf.st_size;
	file.val_time = buf.st_mtime;
	file.time = ft_time_calc(&buf.st_mtime);
	file.minor = minor(buf.st_rdev);
	file.major = major(buf.st_rdev);
	file.blocks = buf.st_blocks;
	return (file);
}
