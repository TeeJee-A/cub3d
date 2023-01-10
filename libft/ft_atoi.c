/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:24 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 15:11:28 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		signe;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * signe);
}
