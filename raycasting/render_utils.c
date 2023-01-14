/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:28:23 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/14 13:00:24 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

void	ft_put_mini(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = x * SIZE_MINI;
	while (i < x * SIZE_MINI + SIZE_MINI
		&& i >= 0 && i <= data->var.win_height * SIZE_MINI)
	{
		j = y * SIZE_MINI;
		while (j < y * SIZE_MINI + SIZE_MINI
			&& j >= 0 && j <= data->var.win_width * SIZE_MINI)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

void	square(t_data *data, int x, int y, int color)
{
	int	i;

	i = -1;
	while (++i <= SIZE_MINI)
	{
		my_mlx_pixel_put(data, x, y + i, color);
		my_mlx_pixel_put(data, x + SIZE_MINI, \
		y + i, color);
		my_mlx_pixel_put(data, x + i, y, color);
		my_mlx_pixel_put(data, x + i, \
		y + SIZE_MINI, color);
	}
}

void	draw_case(t_data *data, int color)
{
	ft_put_mini(data, data->var.i, data->var.j, color);
	square(data, data->var.j * SIZE_MINI, data->var.i * SIZE_MINI, \
	data->square_color);
}

void	draw_circle(t_data *data, int x, int y, int r)
{
	double	i;
	double	j;
	double	angle;
	double	x1;
	double	y1;

	j = 0;
	while (j < r)
	{
		i = 0;
		while (i < 360)
		{
			angle = i;
			x1 = j * cos(angle * M_PI / 180);
			y1 = j * sin(angle * M_PI / 180);
			my_mlx_pixel_put(data, y + y1, \
			x + x1, data->ply.color);
			i += 0.1;
		}
		j += 0.1;
	}
}

int	render_map(t_data *data)
{
	data->var.i = -1;
	while (data->secondlines[++data->var.i])
	{
		data->var.j = -1;
		while (data->secondlines[data->var.i][++data->var.j])
		{
			if (data->secondlines[data->var.i][data->var.j] == '1')
				draw_case(data, 0xFF0000);
			else if (data->secondlines[data->var.i][data->var.j] == '0')
				ft_put_mini(data, data->var.i, data->var.j, 0xFFFFFF);
			else if (data->secondlines[data->var.i][data->var.j] == ' ')
				ft_put_mini(data, data->var.i, data->var.j, 0xFF000000);
			else
			{
				if (data->ply.x1 == -1 && data->ply.y1 == -1)
					render_player(data, SIZE_MINI / 8);
				else
					ft_put_mini(data, data->var.i, data->var.j, 0xFFFFFF);
			}
		}
	}
	return (0);
}
