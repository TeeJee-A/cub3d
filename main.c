/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:49:13 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 19:59:53 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsingcub3d/cub3d.h"

void	dividingmap(t_data *data)
{
	data->dividingmap = 0;
	data->countsecondlines = data->countlines - data->countfirstlines;
	data->firstlines = (char **)malloc(sizeof(char *) \
		* (data->countfirstlines + 1));
	data->secondlines = (char **)malloc(sizeof(char *) \
		* (data->countsecondlines + 1));
	if (!data->firstlines || !data->secondlines)
		return ;
	while (data->dividingmap < data->countfirstlines)
	{
		data->firstlines[data->dividingmap]
			= ft_strdup(data->allmap[data->dividingmap]);
		data->dividingmap++;
	}
	data->firstlines[data->dividingmap] = NULL;
	data->dividingmap = 0;
	data->djvjdjngmap = data->countfirstlines;
	while (data->dividingmap < data->countsecondlines)
	{
		data->secondlines[data->dividingmap]
			= ft_strdup(data->allmap[data->djvjdjngmap]);
		data->dividingmap++;
		data->djvjdjngmap++;
	}
	data->secondlines[data->dividingmap] = NULL;
}

void	set_images(t_data *data)
{
	data->var.img_mini.img = mlx_new_image(data->var.mlx, \
	data->var.win_width * SIZE_MINI + 1, data->var.win_height * SIZE_MINI + 1);
	data->var.img_mini.addr = mlx_get_data_addr(data->var.img_mini.img, \
	&data->var.img_mini.bits_per_pixel, \
	&data->var.img_mini.line_length, &data->var.img_mini.endian);
}

void	unit_mlx_p(t_data *data)
{
	data->var.mlx = mlx_init();
	if (data->var.mlx == NULL)
		error_msg("Error in mlx");
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (check_arguments(ac, av[1]) == false)
		return (1);
	if (readfromfile(av[1], data) == false)
		return (1);
	data->countfirstlines = countlinesfirstmap(data);
	dividingmap(data);
	if (parsemap(data) == false)
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
