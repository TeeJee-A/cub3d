/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:30:41 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/11 15:08:56 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

void	set_rotation(t_data *data, char c)
{
	if (c == 'S')
		data->ply.rotation_angle = 0;
	else if (c == 'E')
		data->ply.rotation_angle = M_PI_2;
	else if (c == 'N')
		data->ply.rotation_angle = M_PI;
	else
		data->ply.rotation_angle = 3 * M_PI_2;
}

double	mod(double x, double y)
{
	while (x >= y)
		x -= y;
	if (x < 0)
		x += y;
	return (x);
}

void	render_player(t_data *data, int r)
{
	data->ply.x1 = data->var.i * SIZE_MINI + SIZE_MINI / 2;
	data->ply.y1 = data->var.j * SIZE_MINI + SIZE_MINI / 2;
	draw_circle(data, data->ply.x1, data->ply.y1, r);
	square(data, data->var.j * SIZE_MINI, data->var.i * SIZE_MINI, \
	data->square_color);
}

void	init2(t_data *data)
{
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

void	init1(t_data *data)
{
	data->ply.x1 = -1;
	data->ply.y1 = -1;
	data->fov_angle = (60 * (M_PI / 180));
	data->ply.walk_speed = 10.0;
	data->ply.turn_speed = (10 * (M_PI / 180));
	data->ply.rotation_angle = 0;
	data->ply.ray_angle = data->ply.rotation_angle - (data->fov_angle / 2);
	data->ply.turn_dir = 0;
	data->ply.walk_dir = 0;
	data->ply.side_dir = 0;
	data->ply.color = 0x00FF00;
	data->ray_color = 0xFFFF00;
	data->square_color = 0x0000FF;
	data->wall_color = 0x00FF00;
}
