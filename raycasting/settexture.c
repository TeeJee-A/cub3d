/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settexture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:29:14 by ataji             #+#    #+#             */
/*   Updated: 2023/01/19 21:24:28 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

void	settexture(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "EA"))
		data->texture[EA] = ft_strdup(elements[1]);
	else if (!ft_strcmp(elements[0], "WE"))
		data->texture[WE] = ft_strdup(elements[1]);
	else if (!ft_strcmp(elements[0], "SO"))
		data->texture[SO] = ft_strdup(elements[1]);
	else if (!ft_strcmp(elements[0], "NO"))
		data->texture[NO] = ft_strdup(elements[1]);
}

bool	checktexture(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "WE"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->we++;
	}
	if (!ft_strcmp(elements[0], "SO"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->so++;
	}
	if (!ft_strcmp(elements[0], "NO"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->no++;
	}
	if (!ft_strcmp(elements[0], "EA"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->ea++;
	}
	return (true);
}

void	createtextureimg(t_data *data)
{
	data->textureimg[EA].img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[EA], &data->textureimg[EA].width, \
			&data->textureimg[EA].heigth);
	data->textureimg[WE].img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[WE], &data->textureimg[WE].width, \
			&data->textureimg[WE].heigth);
	data->textureimg[SO].img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[SO], &data->textureimg[SO].width, \
			&data->textureimg[SO].heigth);
	data->textureimg[NO].img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[NO], &data->textureimg[NO].width, \
			&data->textureimg[NO].heigth);
	data->textureimg[EA].add = (int *)mlx_get_data_addr \
		(data->textureimg[EA].img, &data->textureimg[EA].bits_per_pixel, \
			&data->textureimg[EA].line_length, &data->textureimg[EA].endian);
	data->textureimg[NO].add = (int *)mlx_get_data_addr \
		(data->textureimg[NO].img, &data->textureimg[NO].bits_per_pixel, \
			&data->textureimg[NO].line_length, &data->textureimg[NO].endian);
	data->textureimg[SO].add = (int *)mlx_get_data_addr \
		(data->textureimg[SO].img, &data->textureimg[SO].bits_per_pixel, \
			&data->textureimg[SO].line_length, &data->textureimg[SO].endian);
	data->textureimg[WE].add = (int *)mlx_get_data_addr \
		(data->textureimg[WE].img, &data->textureimg[WE].bits_per_pixel, \
			&data->textureimg[WE].line_length, &data->textureimg[WE].endian);
}
