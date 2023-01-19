/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatexy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:33:24 by ataji             #+#    #+#             */
/*   Updated: 2023/01/19 16:33:58 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

int	calculatex(t_data *data, int i, int direction)
{
	int	x;

	x = 0;
	if (data->rays[i].ver)
		x = (data->rays[i].y / IMG_SIZE - (int)data->rays[i].y / IMG_SIZE)
			* data->textureimg[direction].width;
	else
		x = (data->rays[i].x / IMG_SIZE - (int)data->rays[i].x / IMG_SIZE)
			* data->textureimg[direction].width;
	return (x);
}

int	calculatey(t_data *data, int j, int direction)
{
	int		y;

	y = (j - data->walltoppixel)
		* ((double)data->textureimg[direction].heigth / data->wallstripheight);
	return (y);
}
