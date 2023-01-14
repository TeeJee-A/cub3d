/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:27:42 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/10 19:40:08 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

double	next_x_pos(t_data *data)
{
	double	x;

	x = data->ply.x1 + cos(data->ply.rotation_angle) \
	* data->ply.walk_dir * data->ply.walk_speed;
	return (x);
}

double	next_y_pos(t_data *data)
{
	double	y;

	y = data->ply.y1 + sin(data->ply.rotation_angle) \
	* data->ply.walk_dir * data->ply.walk_speed;
	return (y);
}

double	next_x_pos_side(t_data *data)
{
	double	x;

	x = data->ply.x1 + cos(data->ply.rotation_angle + (90 * M_PI / 180)) \
	* data->ply.side_dir * data->ply.walk_speed;
	return (x);
}

double	next_y_pos_side(t_data *data)
{
	double	y;

	y = data->ply.y1 + sin(data->ply.rotation_angle + (90 * M_PI / 180)) \
	* data->ply.side_dir * data->ply.walk_speed;
	return (y);
}
