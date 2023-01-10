/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:32:41 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/10 19:50:19 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

void	check_dir_ray(t_data *data, double ray_angle)
{
	data->ray.is_down = 0;
	data->ray.is_up = 0;
	data->ray.is_left = 0;
	data->ray.is_right = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		data->ray.is_down = 1;
	else
		data->ray.is_up = 1;
	if (ray_angle < (M_PI_2) || ray_angle > (3 * M_PI_2))
		data->ray.is_right = 1;
	else
		data->ray.is_left = 1;
}

void	boucle_for_wall_hor(t_data *data)
{
	double	y;

	while (data->ray.next_hor_touch_x >= 0
		&& data->ray.next_hor_touch_x < (data->var.win_height * SIZE_MINI)
		&& data->ray.next_hor_touch_y >= 0
		&& data->ray.next_hor_touch_y < (data->var.win_width * SIZE_MINI))
	{
		if (data->ray.is_up)
			y = data->ray.next_hor_touch_y - 1;
		else
			y = data->ray.next_hor_touch_y;
		data->ray.i = data->ray.next_hor_touch_x / SIZE_MINI;
		data->ray.j = y / SIZE_MINI;
		if (data->secondlines[data->ray.i][data->ray.j] == '1')
			return ;
		data->ray.next_hor_touch_x += data->ray.xstep_hor;
		data->ray.next_hor_touch_y += data->ray.ystep_hor;
	}
}

void	boucle_for_wall_ver(t_data *data)
{
	double	x;

	while (data->ray.next_ver_touch_x >= 0
		&& data->ray.next_ver_touch_x < (data->var.win_height * SIZE_MINI)
		&& data->ray.next_ver_touch_y >= 0
		&& data->ray.next_ver_touch_y < (data->var.win_width * SIZE_MINI))
	{
		if (data->ray.is_left)
			x = data->ray.next_ver_touch_x - 1;
		else
			x = data->ray.next_ver_touch_x;
		data->ray.i = x / SIZE_MINI;
		data->ray.j = data->ray.next_ver_touch_y / SIZE_MINI;
		if (data->secondlines[data->ray.i][data->ray.j] == '1')
			return ;
		data->ray.next_ver_touch_x += data->ray.xstep_ver;
		data->ray.next_ver_touch_y += data->ray.ystep_ver;
	}
}

void	check_hor_int(t_data *data, double x, double y, double ray_angle)
{
	data->ray.yinter_hor = floor(y / SIZE_MINI) * SIZE_MINI;
	if (data->ray.is_down)
		data->ray.yinter_hor += SIZE_MINI;
	data->ray.xinter_hor = x + ((data->ray.yinter_hor - y) / tan(ray_angle));
	data->ray.ystep_hor = SIZE_MINI;
	if (data->ray.is_up)
		data->ray.ystep_hor *= -1;
	data->ray.xstep_hor = SIZE_MINI / tan(ray_angle);
	if ((data->ray.is_left && data->ray.xstep_hor > 0)
		|| (data->ray.is_right && data->ray.xstep_hor < 0))
		data->ray.xstep_hor *= -1;
	data->ray.next_hor_touch_x = data->ray.xinter_hor;
	data->ray.next_hor_touch_y = data->ray.yinter_hor;
	boucle_for_wall_hor(data);
}

void	check_ver_int(t_data *data, double x, double y, double ray_angle)
{
	data->ray.xinter_ver = floor(x / SIZE_MINI) * SIZE_MINI;
	if (data->ray.is_right)
		data->ray.xinter_ver += SIZE_MINI;
	data->ray.yinter_ver = y + ((data->ray.xinter_ver - x) * tan(ray_angle));
	data->ray.xstep_ver = SIZE_MINI;
	if (data->ray.is_left)
		data->ray.xstep_ver *= -1;
	data->ray.ystep_ver = SIZE_MINI * tan(ray_angle);
	if ((data->ray.is_up && data->ray.ystep_ver > 0)
		|| (data->ray.is_down && data->ray.ystep_ver < 0))
		data->ray.ystep_ver *= -1;
	data->ray.next_ver_touch_x = data->ray.xinter_ver;
	data->ray.next_ver_touch_y = data->ray.yinter_ver;
	boucle_for_wall_ver(data);
}
