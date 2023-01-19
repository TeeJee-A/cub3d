/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:33:29 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/19 22:10:27 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	dda(t_data *data, double x, double y)
{
	t_dda	var;

	var.x = data->ply.x1;
	var.y = data->ply.y1;
	var.dx = x - var.x;
	var.dy = y - var.y;
	var.steps = fmax(fabs(var.dy), fabs(var.dx));
	var.inc_x = var.dx / var.steps;
	var.inc_y = var.dy / var.steps;
	data->var.i = -1;
	while (++data->var.i < var.steps)
	{
		my_mlx_pixel_put(data, \
			(int)(var.y), (int)(var.x), data->ray_color);
		var.x += var.inc_x;
		var.y += var.inc_y;
	}
}

double	calcule_dis(double x1, double y1, double x2, double y2)
{
	double	final;

	final = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (final);
}

void	initialisation(t_data *data)
{
	data->ply.x1 = -1;
	data->ply.y1 = -1;
	data->fov_angle = (60 * (M_PI / 180));
	data->ply.walk_speed = 5.0;
	data->ply.turn_speed = (5 * (M_PI / 180));
	data->ply.rotation_angle = 0;
	data->ply.ray_angle = data->ply.rotation_angle - (data->fov_angle / 2);
	data->ply.turn_dir = 0;
	data->ply.walk_dir = 0;
	data->ply.side_dir = 0;
	data->ply.color = 0x00FF00;
	data->ray_color = 0xFFFF00;
	data->square_color = 0xFFFF00;
	data->wall_color = 0x00FF00;
	data->ray.is_down = 0;
	data->ray.is_up = 0;
	data->ray.is_right = 0;
	data->ray.is_left = 0;
	data->hor_dis = 0;
	data->ver_dis = 0;
	data->dis = 0;
	data->scal = IMG_SIZE / SIZE_MINI;
	data->max_dis = 0;
	data->mouse = 1e15;
}

void	error_msg(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	exit(0);
}
