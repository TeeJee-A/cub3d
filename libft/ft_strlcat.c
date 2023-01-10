/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:45:40 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 14:59:22 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && i + j < dstsize - 1 && dstsize != 0)
	{
		dst[i + j] = src[j];
		j++;
		dst[i + j] = '\0';
	}
	while (src[j] != '\0')
		j++;
	if (dstsize <= i)
		return (j + dstsize);
	return (j + i);
}
