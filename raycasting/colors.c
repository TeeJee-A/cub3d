/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:28 by ataji             #+#    #+#             */
/*   Updated: 2023/01/19 22:52:26 by ataji            ###   ########.fr       */
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

int	returncolor(t_data *data, int direction, int j)
{
	int	color;
	int	index;

	data->texturey = calculatey(data, j, direction);
	index = (data->texturey
			* data->textureimg[direction].width + data->texturex);
	color = (data->textureimg[direction].add[index]);
	return (color);
}

int	setcolor(t_data *data, int i, int j)
{
	int	color;

	color = 0;
	if (!data->rays[i].ver && data->rays[i].up)
		color = returncolor(data, NO, j);
	else if (!data->rays[i].ver && data->rays[i].down)
		color = returncolor(data, SO, j);
	else if (data->rays[i].ver && data->rays[i].left)
		color = returncolor(data, WE, j);
	else if (data->rays[i].ver && data->rays[i].right)
		color = returncolor(data, EA, j);
	return (color);
}
