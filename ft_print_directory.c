/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:21:45 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 08:32:01 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "ft_ls.h"
#include "ft_printf.h"

/*
** Ft_recursive checks if the 'R' flag is activated created a new path
** if a directory is found and send these informations back to
** ft_print_directory
*/

void	ft_recursive_print(t_lst *save, const char *path, char *flag)
{
	char	*new_path;
	DIR		*directory;

	while (save->elem.name && ft_strchr(flag, 'R'))
	{
		if ((save->elem.name[0]) == '.' && !ft_strchr(flag, 'a'))
			;
		else if (save->elem.rights[0] == 'd' && ft_strcmp(save->elem.name, ".")
				&& ft_strcmp(save->elem.name, ".."))
		{
			if (path[0] != '/' || path[1] != '\0')
				new_path = ft_strjoin(path, "/", 0);
			else
				new_path = ft_strdup(path);
			new_path = ft_strjoin(new_path, save->elem.name, 1);
			ft_printf("\n%s:\n", new_path);
			directory = opendir(new_path);
			ft_print_directory(directory, new_path, flag);
			if (directory)
				closedir(directory);
			free(new_path);
		}
		save = save->nxt;
	}
}

/*
** Ft_print_directory is the heart of ft_ls when it comes to dealing
** with directories
**
** First the function creates a list with the elements in "directory"
**
** Then they are sorted according to the flags used by the user
**
** Then they are printed on the terminal
**
** If the 'R' flag is activated, ft_recursive_print will check the directories
** in "directory" and relaunch ft_print_directory
**
** Finally the element in the save_lst are freed
*/

void	ft_print_directory(DIR *directory, const char *path, char *flag)
{
	t_lst	*save;
	int		i;

	i = ft_strlen(path) - 1;
	save = NULL;
	if (directory)
	{
		save = ft_create_lst(directory, path, flag);
		save = ft_sort_lst(&save, flag);
		ft_print_lst(save, flag, 1);
		ft_recursive_print(save, path, flag);
		while (save->elem.name)
		{
			ft_free_elem(save->elem);
			save = save->nxt;
			free(save->previous);
		}
		free(save);
	}
	else
	{
		while (path[i] && path[i] != '/')
			i--;
		ft_printf("ft_ls: %s: Permission denied\n", path + i + 1);
	}
}
