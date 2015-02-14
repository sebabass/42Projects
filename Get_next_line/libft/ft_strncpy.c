/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:40:40 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/06 17:16:08 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (src[i])
			dst[i] = src[i];
		else
			dst[i] = 0;
		i++;
	}
	return (dst);
}
