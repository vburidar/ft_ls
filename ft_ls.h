/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:06:46 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 09:07:16 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>

/*
** S_tabdir stores all the data regarding a file/directory
*/

typedef struct		s_tabdir
{
	DIR				*dir;
	char			*path;
	int				file;
	char			*name;
	char			*rights;
	int				link;
	char			*owner_name;
	char			*group_name;
	int				size;
	char			*time;
	int				major;
	int				minor;
	int				blocks;
	unsigned long	val_time;
}					t_tab_dir;

/*
** s_length is used to print the attributes of the files properly
** aligned when the 'l' flag is active
*/

typedef struct		s_length
{
	int				l_link;
	int				l_oname;
	int				l_gname;
	int				l_size;
	int				l_time;
	int				l_minor;
	int				l_major;
}					t_length;

/*
** s_lst stores a list of file and directories that are stored in one
** specific directory
*/

typedef struct		s_lst
{
	t_tab_dir		elem;
	struct s_lst	*nxt;
	struct s_lst	*previous;
}					t_lst;

t_lst				*ft_create_lst(DIR *dir, const char *path, char *flag);
void				ft_print_directory(DIR *dir, const char *path, char *flag);
void				ft_print_lst(t_lst *lst, char *flag, int i);
void				ft_free_elem(t_tab_dir elem);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_inittabdir(char **argv, t_lst **lst, char *flag);
char				*ft_get_flag(char **argv);
t_lst				*ft_sort_lst(t_lst **lst, char *flag);
t_lst				*ft_sort_time(t_lst *lst);
t_tab_dir			ft_get_l(struct stat b, char *p, t_tab_dir f, char *flag);
void				ft_printl(t_lst *lst, char *flag, int input);
int					ft_test_file(char *arg, t_tab_dir *tab, int j, char *flag);
t_lst				*ft_swap_lst(t_lst *elem1, t_lst *elem2);
char				*ft_time_calc(const time_t *time_file);
char				*ft_rights(char *rights);
t_tab_dir			ft_type(t_tab_dir file, mode_t mod, char*path, char *flag);
t_length			ft_max_len(t_lst *lst, t_length len, char *flag, int *tot);
void				ft_init_len(t_length *len);
t_lst				*ft_init_link(t_lst *lst);
#endif
