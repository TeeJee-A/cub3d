/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate3dprojection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:43:34 by ataji             #+#    #+#             */
/*   Updated: 2023/01/15 19:09:38 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

int	createcolorceil(t_data *data)
{
	return ((ft_atoi(data->ceil[0]) << 16) | (ft_atoi(data->ceil[1]) << 8)
		| ft_atoi(data->ceil[2]));
}

int	createcolorfloor(t_data *data)
{
	return ((ft_atoi(data->floor[0]) << 16) | (ft_atoi(data->floor[1]) << 8)
		| ft_atoi(data->floor[2]));
}

int	calculatex(t_data *data, int i)
{
	int	x;

	x = 0;
	if (data->rays[i].ver)
		x = (int)data->rays[i].y % IMG_SIZE;
	else
		x = (int)data->rays[i].x % IMG_SIZE;
	return (x);
}

int	calculatey(t_data *data, int j)
{
	int	y;

	y = (j - data->walltoppixel)
		* data->textureimg[EA]->heigth / data->wallstripheight;
	return (y);
}

void	generate3dprojection(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	createtextureimg(data);
	while (++i < data->num_rays)
	{
		data->distanceprojplane = (WIDTH / 2) / tan(data->fov_angle / 2);
		data->projectionwallheight = (double)(IMG_SIZE / data->rays[i].cor)
			* data->distanceprojplane;
		data->wallstripheight = data->projectionwallheight;
		data->walltoppixel = (HEIGHT / 2) - (data->wallstripheight / 2);
		if (data->walltoppixel < 0)
			data->walltoppixel = 0;
		data->wallbottompixel = (HEIGHT / 2) + (data->wallstripheight / 2);
		if (data->wallbottompixel > HEIGHT)
			data->wallbottompixel = HEIGHT;
		j = -1;
		while (++j < data->walltoppixel)
			my_mlx_pixel_put_map(data, i, j, createcolorceil(data));
		j = data->walltoppixel - 1;
		data->texturex = calculatex(data, i);
		while (++j < data->wallbottompixel)
		{
			data->texturey = calculatey(data, j);
			color = *(int *)(data->textureimg[EA]->addr
					+ (data->texturey % data->textureimg[EA]->heigth)
					* data->textureimg[EA]->line_length
					+ (data->texturex % data->textureimg[EA]->width)
					* data->textureimg[EA]->bits_per_pixel / 8);
			my_mlx_pixel_put_map(data, data->texturex, data->texturey, color);
		}
		j = data->wallbottompixel - 1;
		while (++j < HEIGHT)
			my_mlx_pixel_put_map(data, i, j, createcolorfloor(data));
	}
}
