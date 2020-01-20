/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:37:05 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/19 16:38:30 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
     struct dirent {  when _DARWIN_FEATURE_64_BIT_INODE is NOT defined 
             ino_t      d_ino;                ** file number of entry 
             __uint16_t d_reclen;             ** length of this record 
             __uint8_t  d_type;               * file type, see below 
             __uint8_t  d_namlen;             ** length of string in d_name 
             char    d_name[255 + 1];    name must be no longer than this 
     };
*/

/*
     struct stat { 		** when _DARWIN_FEATURE_64_BIT_INODE is NOT defined 
         dev_t    st_dev;    ** device inode resides on 
         ino_t    st_ino;    ** inode's number 
         mode_t   st_mode;   ** inode protection mode 
         nlink_t  st_nlink;  ** number of hard links to the file 
         uid_t    st_uid;    ** user-id of owner 
         gid_t    st_gid;    ** group-id of owner 
         dev_t    st_rdev;   ** device type, for special file inode 
         struct timespec st_atimespec;  ** time of last access 
         struct timespec st_mtimespec;  ** time of last data modification 
         struct timespec st_ctimespec;  ** time of last file status change 
         off_t    st_size;   ** file size, in bytes 
         quad_t   st_blocks; ** blocks allocated for file 
         u_long   st_blksize;** optimal file sys I/O ops blocksize 
         u_long   st_flags;  ** user defined flags for file 
         u_long   st_gen;    ** file generation number 
     };

struct stat {
               dev_t     st_dev;     ** ID of device containing file 
               ino_t     st_ino;     ** inode number 
               mode_t    st_mode;    ** protection 
               nlink_t   st_nlink;   ** number of hard links 
               uid_t     st_uid;     ** user ID of owner 
               gid_t     st_gid;     ** group ID of owner 
               dev_t     st_rdev;    ** device ID (if special file) 
               off_t     st_size;    ** total size, in bytes 
               blksize_t st_blksize; ** blocksize for file system I/O 
               blkcnt_t  st_blocks;  ** number of 512B blocks allocated 
               time_t    st_atime;   ** time of last access 
               time_t    st_mtime;   ** time of last modification 
               time_t    st_ctime;   ** time of last status change 
           };
*/
#ifndef LS_H
# define LS_H
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <pwd.h>
#include <time.h>
#include <grp.h>

#include <dirent.h>
#include <uuid/uuid.h>

typedef struct dirent p_dirent;

typedef struct stat p_stat;
/*
typedef struct dirent
{
  ino_t d_ino;
  off_t d_off;
  unsigned short d_reclen;
  char d_name[];
} p_dirent;
*/

typedef struct		i_lst
{
	//p_dirent *dp;
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

	struct i_lst	*next;
}			 		p_lst;

p_lst	*lst_new(p_dirent *dp, p_stat *stats);

void	lst_pushback(p_lst *list, p_lst *toadd);
void	lst_free(p_lst *list);

void	lst_sort_byname(p_lst *list);
void	lst_sort_bytime(p_lst *list);
void	lst_sort_rev(p_lst *list, char *options);

void	lst_print_l(p_lst *list, char *options, int xfiles);
void	lst_print_all(p_lst *list, char *options, int xfiles);
void	lst_print_name(p_lst *list, char *options, int xfiles);
void	lst_print_max(p_lst *list, char *options, int xfiles);
void	putstr(char *s);
void	ft_putchar(char c);

void	links_sp_updt(p_lst *list);
void	size_sp_updt(p_lst *list);
void	lst_swap(p_lst *lst);
void	ft_putllnbr(long long int n);

char	*permi_conv(mode_t mode);
char	*cutt(char *old);
char	*ltoa(long int n);
char	*file_type(mode_t m);
char	*filter_tmp(char *tmp);
char	*dup_sp_free(char *s1, int nb);
char	*ft_strdup(char *s1);
char	*strdup_free(char *s1);
char	*ft_strjoin(char *s1, char *s2);/////
char	*strjoin_free(char *s1, char *s2, char *tmp);
char	*strjoin_free1(char *s1, char *s2);

long int	print_blocksize(p_lst *list);
long int	print_blocksize_l(p_lst *list);

int		is_option(int ac, char **av, char o);
int		is_in(char *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strln(char *s);
int		errors(int ac, char **av);
int		is_bralrt(char *s);


char *add_options(char *s, char *options);
int	flag_xfiles(int ac, char **av);

void			ft_printf(char *str, ...);
#endif
