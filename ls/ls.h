/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:37:05 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/21 09:49:57 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     struct dirent {  when _DARWIN_FEATURE_64_BIT_INODE is NOT defined
**            ino_t      d_ino;                ** file number of entry
**            __uint16_t d_reclen;             ** length of this record
**             __uint8_t  d_type;               * file type, see below
**             __uint8_t  d_namlen;             ** length of string in d_name
**             char    d_name[255 + 1];    name must be no longer than this
**     };
**
**
**
**     struct stat { 		** when _DARWIN_FEATURE_64_BIT_INODE is NOT defined
**        dev_t    st_dev;    ** device inode resides on
**         ino_t    st_ino;    ** inode's number
**         mode_t   st_mode;   ** inode protection mode
**         nlink_t  st_nlink;  ** number of hard links to the file
**         uid_t    st_uid;    ** user-id of owner
**         gid_t    st_gid;    ** group-id of owner
**         dev_t    st_rdev;   ** device type, for special file inode
**         struct timespec st_atimespec;  ** time of last access
**         struct timespec st_mtimespec;  ** time of last data modification
**         struct timespec st_ctimespec;  ** time of last file status change
**         off_t    st_size;   ** file size, in bytes
**         quad_t   st_blocks; ** blocks allocated for file
**         u_long   st_blksize;** optimal file sys I/O ops blocksize
**         u_long   st_flags;  ** user defined flags for file
**         u_long   st_gen;    ** file generation number
**     };
**
**struct stat {
**               dev_t     st_dev;     ** ID of device containing file
**               ino_t     st_ino;     ** inode number
**               mode_t    st_mode;    ** protection
**               nlink_t   st_nlink;   ** number of hard links
**               uid_t     st_uid;     ** user ID of owner
**               gid_t     st_gid;     ** group ID of owner
**               dev_t     st_rdev;    ** device ID (if special file)
**               off_t     st_size;    ** total size, in bytes
**               blksize_t st_blksize; ** blocksize for file system I/O
**              blkcnt_t  st_blocks;  ** number of 512B blocks allocated
**               time_t    st_atime;   ** time of last access
**               time_t    st_mtime;   ** time of last modification
**               time_t    st_ctime;   ** time of last status change
**           };
*/

#ifndef LS_H
# define LS_H
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <dirent.h>
# include <uuid/uuid.h>

typedef struct dirent	t_dirent;

typedef struct stat		t_stat;

typedef struct		s_lst
{
	char			*type;
	char			*permi;
	char			*links;
	char			*user;
	char			*group;
	char			*size;
	char			*tmodif;
	char			*name;

	char			*path;
	long int		blocks;
	unsigned int	mtime;

	struct s_lst	*next;
}					t_lst;

t_lst				*lst_new(t_dirent *dp, t_stat *stats);

void				lst_pushback(t_lst *list, t_lst *toadd);
void				lst_free(t_lst *list);

void				lst_sort_byname(t_lst *list);
void				lst_sort_bytime(t_lst *list);
void				lst_sort_rev(t_lst *list, char *options);

void				lst_print_l(t_lst *list, char *options, int xfiles);
void				lst_print_all(t_lst *list, char *options, int xfiles);
void				lst_print_name(t_lst *list, char *options, int xfiles);
void				lst_print_max(t_lst *list, char *options, int xfiles);
void				putstr(char *s);
void				ft_putchar(char c);

void				links_sp_updt(t_lst *list);
void				size_sp_updt(t_lst *list);
void				lst_swap(t_lst *lst);
void				ft_putllnbr(long long int n);

char				*permi_conv(mode_t mode);
char				*cutt(char *old);
char				*ltoa(long int n);
char				*file_type(mode_t m);
char				*filter_tmp(char *tmp);
char				*dup_sp_free(char *s1, int nb);
char				*ft_strdup(char *s1);
char				*strdup_free(char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				*strjoin_free(char *s1, char *s2, char *tmp);
char				*strjoin_free1(char *s1, char *s2);

long int			print_blocksize(t_lst *list);
long int			print_blocksize_l(t_lst *list);

int					is_option(int ac, char **av, char o);
int					is_in(char *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strln(char *s);
int					errors(int ac, char **av);
int					is_bralrt(char *s);
int					no_file_param(int ac, char **av);
int					print_folder_content(char *path, char *options, int xfiles);

char				*add_options(char *s, char *options);
int					flag_xfiles(int ac, char **av);

void				free_stuff(t_stat *stats, char *path, char *tmp);
void				free_stuff2(t_stat *stats, char *tmp, t_lst *list);
void				options_and_print(t_lst *list, char *options, int xfiles);

#endif
