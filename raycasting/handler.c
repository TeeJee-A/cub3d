/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:32:02 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/10 19:39:56 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
		exit(0);
	else if (keysym == 0)
		move_player(data, keysym);
	else if (keysym == 1)
		move_player(data, keysym);
	else if (keysym == 2)
		move_player(data, keysym);
	else if (keysym == 13)
		move_player(data, keysym);
	else if (keysym == 123)
		move_player(data, keysym);
	else if (keysym == 124)
		move_player(data, keysym);
	data->ply.rotation_angle = mod(data->ply.rotation_angle, (2.0 * M_PI));
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 0)
		ft_reset(data, keysym);
	else if (keysym == 1)
		ft_reset(data, keysym);
	else if (keysym == 2)
		ft_reset(data, keysym);
	else if (keysym == 13)
		ft_reset(data, keysym);
	else if (keysym == 123)
		ft_reset(data, keysym);
	else if (keysym == 124)
		ft_reset(data, keysym);
	return (0);
}

int	handle_btnrealease(int keycode, t_var *var)
{
	(void)keycode;
	(void)var;
	exit(0);
	return (0);
}

int	handle_mouse(int x, int y, t_data *data)
{
	mlx_clear_window(data->var.mlx, data->var.win);
	(void)y;
	if (data->mouse != 1e15)
	{
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		{
			if (data->mouse < x)
				data->ply.turn_dir = -1;
			else
				data->ply.turn_dir = 1;
			data->ply.rotation_angle += (data->ply.turn_dir \
			* 0.02);
			data->mouse = x;
		}
		render(data);
	}
	else
		data->mouse = x;
	return (0);
}
