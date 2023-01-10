/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:28:32 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 19:46:24 by aanjaimi         ###   ########.fr       */
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
# include<math.h>
# include<mlx.h>

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

# define IMG_SIZE 40
# define SIZE_MINI 10
# define WALL_STR_WIDTH 1
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_rays
{
	double	x;
	double	y;
	double	dis;
	int		ver;
	double	cor;
	double	ang;
	int		up;
	int		down;
	int		right;
	int		left;
}	t_rays;

typedef struct s_ray
{
	double	xstep_hor;
	double	ystep_hor;
	double	xstep_ver;
	double	ystep_ver;
	double	xinter_hor;
	double	yinter_hor;
	double	xinter_ver;
	double	yinter_ver;
	double	next_hor_touch_x;
	double	next_hor_touch_y;
	double	next_ver_touch_x;
	double	next_ver_touch_y;
	int		is_down;
	int		is_up;
	int		is_right;
	int		is_left;
	int		i;
	int		j;
}t_ray;

typedef struct s_dda
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		inc_x;
	double		inc_y;
	double		steps;
}t_dda;

typedef struct s_player
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	turn_dir;
	double	walk_dir;
	double	side_dir;
	double	rotation_angle;
	double	ray_angle;
	double	walk_speed;
	double	turn_speed;
	int		color;
}t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_var
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*line;
	int		somme;
	int		a;
	char	**d;
	int		win_height;
	int		win_width;
	int		win_height_mini;
	int		win_width_mini;
	void	*mlx;
	void	*win;
	t_img	img_mini;	
	t_img	img_map;
}	t_var;

typedef struct s_data
{
	int				dividingmap;
	int				djvjdjngmap;
	char			**allmap;
	char			**firstlines;
	char			**secondlines;
	int				countlines;
	int				countfirstlines;
	int				countsecondlines;
	int				i;
	int				so;
	int				ea;
	int				no;
	int				we;
	int				c;
	int				f;
	int				counter;
	int				x;
	size_t			biglength;
	size_t			smalllength;
	t_rays			*rays;
	t_var			var;
	t_player		ply;
	t_ray			ray;
	int				p_i;
	int				p_j;
	double			fov_angle;
	double			xx;
	double			yy;
	int				num_rays;
	int				ray_color;
	int				square_color;
	double			hor_dis;
	double			ver_dis;
	double			dis;
	int				scal;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	unsigned int	wall_color;
	double			max_dis;
	int				path_img_width;
	int				path_img_heigth;
	long long		mouse;
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

/**************************** raycasting ****************************/
void	initialisation(t_data *data);
void	error_msg(char *str);
int		init_window(t_data *data);
void	find_p(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);
void	move_player(t_data *data, char direction);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put_map(t_data *data, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
void	ft_reset(t_data *data, char direction);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_btnrealease(int keycode, t_var *var);
void	ft_put(t_data *data, int x, int y, int color);
void	ft_put_mini(t_data *data, int x, int y, int color);
void	draw_circle(t_data *data, int x, int y, int r);
int		render_map(t_data *data);
void	render_player(t_data *data, int r);
int		render(t_data *data);
void	loop_mlx(t_data *data);
int		wall(char *wall);
void	dda(t_data *data, double x, double y);
void	draw_case(t_data *data, int color);
void	square(t_data *data, int x, int y, int color);
double	next_x_pos(t_data *data);
double	next_y_pos(t_data *data);
double	next_x_pos_side(t_data *data);
double	next_y_pos_side(t_data *data);
void	check_wall_ray(t_data *data, double x, double y, double angle);
void	set_rotation(t_data *data, char c);
double	mod(double x, double y);
double	calcule_dis(double x1, double y1, double x2, double y2);
void	calcule_distances(t_data *data);
void	check_hor_int(t_data *data, double x, double y, double ray_angle);
void	check_ver_int(t_data *data, double x, double y, double ray_angle);
void	boucle_for_wall_hor(t_data *data);
void	boucle_for_wall_ver(t_data *data);
void	check_dir_ray(t_data *data, double ray_angle);
void	render_wall_3d(t_data *data);
void	render_rays(t_data *data);
void	clear_color_buffer(t_data *data, int color);
int		create_trgb(int t, int r, int g, int b);
void	img_no(t_data *data, int i, int j, int x);
void	img_so(t_data *data, int i, int j, int x);
void	img_we(t_data *data, int i, int j, int x);
void	img_ea(t_data *data, int i, int j, int x);
int		calc_x(t_data *data, int i);
int		handle_mouse(int x, int y, t_data *data);
void	unit_mlx_p(t_data *data);
#endif
