/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:20:49 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/06 17:17:13 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (j < n)
	{
		dst[i + j] = src[j];
		if (src[j] == '\0')
			return (dst);
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
