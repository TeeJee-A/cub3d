/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:49:13 by ataji             #+#    #+#             */
/*   Updated: 2023/01/13 17:10:21 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsingcub3d/cub3d.h"

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
