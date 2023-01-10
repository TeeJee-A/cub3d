/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:17:38 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 14:51:12 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsin/cub3d.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\n')
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (dest);
}
