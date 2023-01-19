/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate3dprojection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:38:58 by ataji             #+#    #+#             */
/*   Updated: 2023/01/20 00:10:43 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

void	alloperations(t_data *data, int i, int j)
{
	int	color;

	color = setcolor(data, i, j);
	my_mlx_pixel_put_map(data, i, j, color);
}

int	setdirection(t_data *data, int i)
{
	if (!data->rays[i].ver && data->rays[i].up)
		return (NO);
	else if (!data->rays[i].ver && data->rays[i].down)
		return (SO);
	else if (data->rays[i].ver && data->rays[i].left)
		return (WE);
	else if (data->rays[i].ver && data->rays[i].right)
		return (EA);
	return (0);
}

void	generate3dprojection(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->num_rays)
	{
		data->distanceprojplane = (WIDTH / 2) / tan(data->fov_angle / 2);
		data->wallstripheight = (IMG_SIZE / data->rays[i].cor)
			* data->distanceprojplane;
		data->walltoppixel = (HEIGHT / 2) - (data->wallstripheight / 2);
		data->wallbottompixel = (HEIGHT / 2) + (data->wallstripheight / 2);
		j = -1;
		while (++j < data->walltoppixel)
			my_mlx_pixel_put_map(data, i, j, createcolorceil(data));
		j = data->walltoppixel - 1;
		data->texturex = calculatex(data, i, setdirection(data, i));
		while (++j < data->wallbottompixel)
			alloperations(data, i, j);
		j = data->wallbottompixel - 1;
		while (++j < HEIGHT)
			my_mlx_pixel_put_map(data, i, j, createcolorfloor(data));
		i++;
	}
}
