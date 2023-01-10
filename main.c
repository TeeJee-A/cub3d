/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:49:13 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 10:39:36 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (check_arguments(ac, av[1]) == false)
		return (1);
	if (readfromfile(av[1], data) == false)
		return (1);
	data->countfirstlines = countlinesfirstmap(data);
	dividingmap(data);
	if (parsemap(data) == false)
		return (1);
	return (0);
}
