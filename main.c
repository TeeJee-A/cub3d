/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:49:13 by ataji             #+#    #+#             */
/*   Updated: 2023/01/15 19:20:49 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsingcub3d/cub3d.h"

void	createtextureimg(t_data *data)
{
	data->textureimg[EA]->img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[EA], &data->textureimg[EA]->width, \
			&data->textureimg[EA]->heigth);
	data->textureimg[WE]->img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[WE], &data->textureimg[WE]->width, \
			&data->textureimg[WE]->heigth);
	data->textureimg[SO]->img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[SO], &data->textureimg[SO]->width, \
			&data->textureimg[SO]->heigth);
	data->textureimg[NO]->img = mlx_xpm_file_to_image(data->var.mlx, \
		data->texture[NO], &data->textureimg[NO]->width, \
			&data->textureimg[NO]->heigth);
	data->textureimg[EA]->addr = mlx_get_data_addr(data->textureimg[EA]->img, \
		&data->textureimg[EA]->bits_per_pixel, \
			&data->textureimg[EA]->line_length, &data->textureimg[EA]->endian);
	data->textureimg[WE]->addr = mlx_get_data_addr(data->textureimg[WE]->img, \
		&data->textureimg[WE]->bits_per_pixel, \
			&data->textureimg[WE]->line_length, &data->textureimg[WE]->endian);
	data->textureimg[SO]->addr = mlx_get_data_addr(data->textureimg[SO]->img, \
		&data->textureimg[SO]->bits_per_pixel, \
			&data->textureimg[SO]->line_length, &data->textureimg[SO]->endian);
	data->textureimg[NO]->addr = mlx_get_data_addr(data->textureimg[NO]->img, \
		&data->textureimg[NO]->bits_per_pixel, \
			&data->textureimg[NO]->line_length, &data->textureimg[NO]->endian);
}

void	set_images(t_data *data)
{
	data->var.img_mini.img = mlx_new_image(data->var.mlx, \
	data->var.win_width * SIZE_MINI + 1, data->var.win_height * SIZE_MINI + 1);
	data->var.img_mini.addr = mlx_get_data_addr(data->var.img_mini.img, \
	&data->var.img_mini.bits_per_pixel, \
	&data->var.img_mini.line_length, &data->var.img_mini.endian);
	data->var.img_map.img = mlx_new_image(data->var.mlx, WIDTH + 1, HEIGHT + 1);
	data->var.img_map.addr = mlx_get_data_addr(data->var.img_map.img, \
	&data->var.img_map.bits_per_pixel, \
	&data->var.img_map.line_length, &data->var.img_map.endian);
}

void	unit_mlx_p(t_data *data)
{
	data->var.mlx = mlx_init();
	if (data->var.mlx == NULL)
		error_msg("ERROR : Somthing wrong in mlx");
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (allparsing(ac, av, data) == false)
		return (1);
	initialisation(data);
	unit_mlx_p(data);
	init_window(data);
	data->var.win_height = data->countsecondlines;
	data->var.win_width = data->biglength;
	set_images(data);
	find_p(data);
	loop_mlx(data);
	mlx_destroy_image(data->var.mlx, data->var.img_mini.img);
	mlx_destroy_image(data->var.mlx, data->var.img_map.img);
	free(data->rays);
	free(data);
	ft_free(data->var.d);
	return (0);
}
