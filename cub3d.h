/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:28:32 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 10:48:31 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<stdbool.h>
# include<fcntl.h>
# include<limits.h>

# define BUFFER_SIZE 1024 

# define ERRARGUMENTS "ERROR : You should write two arguments\n"
# define ERRFIRSTMAP "ERROR : Somthing wrong in first part of map\n"
# define ERRNAME "ERROR : The map must be named like that \"*.cub\"\n"
# define ERRIMGNAME "ERROR : The map must be named like that \"*.xpm\"\n"
# define ERRSYNMAP "ERROR : The map must had 'SO', 'EA', 'WE', 'NO', 'F', 'C'\n"
# define ERRNUMCOLOR "ERROR : You should write three numbers in RGB color\n"
# define ERRSYNCOLOR "ERROR : The color must be in RGB color system and\
 the number sandwiched between 0 and 255\n"
# define INVMAP "ERROR : Invalid map\n"
# define PLAYERSTART "ERROR : You should write one start of player\n"
# define INTRUDER "ERROR : Attention we have an intruder\n"
# define ERRKEYS "ERROR : Duplicate keys or some keys are missing\n"

typedef struct s_data
{
	int		dividingmap;
	int		djvjdjngmap;
	char	**allmap;
	char	**firstlines;
	char	**secondlines;
	int		countlines;
	int		countfirstlines;
	int		countsecondlines;
	int		i;
	int		so;
	int		ea;
	int		no;
	int		we;
	int		c;
	int		f;
	int		counter;
	int		x;
	size_t	biglength;
	size_t	smalllength;
}t_data;

/**************************** libft ****************************/
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		count_words(const char *str, char c);
char	**ft_freeing(char **tab);
char	**set_words(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**set_wordsnewline(char const *s, char c);
char	**ft_splitnewline(char const *s, char c);
int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strlen(char const *str);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);

/**************************** get_next_line ****************************/
int		get_back_slash_n(char *store_line);
char	*get_line_file(char *static_line, int fd);
char	*rest_line(char *static_line);
char	*get_line_static(char *static_line);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);

/**************************** cub3d.c ****************************/
bool	check_arguments(int numofargs, char *mapname);
bool	readfromfile(char *mapname, t_data *data);

/**************************** cub3d_utils.c ****************************/
void	ft_free(char **tab);
bool	check_point(char *name);
size_t	countecolors(char **colors);
char	*returnline(char *str, size_t len);
void	addspaces(t_data *data);

/**************************** compass_colore.c ****************************/
bool	checkrgb(t_data *data, char **elements);
bool	checkfile(char **elements);
bool	checktexture(t_data *data, char **elements);
bool	checknumbers(char **colors);
bool	checkcolore(char **elements);

/**************************** counters.c ****************************/
int		countlinesfirstmap(t_data *data);
int		countlines(char *mapname);
int		countargs(char *firstline);

/**************************** parser.c ****************************/
bool	checkkeys(t_data *data, char **elements);
bool	checkplayerstart(t_data *data);
bool	parsecharsecondmap(t_data *data);
bool	parsemap(t_data *data);
int		countkeys(char *elements);

/**************************** checkchar.c ****************************/
bool	checkrightleftchar(char *line);
bool	checkbottomtopchar(char **line);
bool	checkchar(t_data *data);

/**************************** parsetwopartsofmap.c ****************************/
bool	parsefirstofmap(t_data *data);
bool	parsesecondofmap(t_data *data);

#endif
