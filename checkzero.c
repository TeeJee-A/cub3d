/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:59:13 by ataji             #+#    #+#             */
/*   Updated: 2023/01/09 21:15:46 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checkrightleftchar(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '0' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
			|| line[i] == 'N')
			if (line[i - 1] == ' ' || line[i + 1] == ' ' || line[i + 1] == '\0')
				return (printf(INVMAP), false);
	}
	return (true);
}

bool	checkbottomtopchar(char **line)
{
	int		i;
	int		j;
	char	helper;

	i = -1;
	while (line[++i])
	{
		j = 0;
		while (line[i][j])
		{
			helper = line[i][j];
			if (helper == '0' || helper == 'S' || helper == 'W' || helper == 'E'
				|| helper == 'N')
				if (line[i - 1][j] == ' ' || line[i + 1][j] == ' ')
					return (printf(INVMAP), false);
			j++;
		}
	}
	return (true);
}

bool	checkfirstchar(t_data *data)
{
	int		i;
	int		j;
	char	helper;

	i = -1;
	while (data->secondlines[++i])
	{
		j = 0;
		while (data->secondlines[i][j] == ' ')
			j++;
		helper = data->secondlines[i][j];
		if (helper == '0' || helper == 'S' || helper == 'W' || helper == 'E'
			|| helper == 'N')
			return (printf(INVMAP), false);
	}
	return (true);
}

bool	checkchar(t_data *data)
{
	int	i;

	i = -1;
	if (checkfirstchar(data) == false)
		return (false);
	while (data->secondlines[++i])
		if (checkrightleftchar(data->secondlines[i]) == false)
			return (false);
	if (checkbottomtopchar(data->secondlines) == false)
		return (false);
	return (true);
}
