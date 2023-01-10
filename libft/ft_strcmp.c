/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:10:48 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 14:59:22 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (!str1 || !str2)
		return (1);
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
