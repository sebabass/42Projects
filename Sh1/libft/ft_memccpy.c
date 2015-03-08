/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:46:15 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/08 18:55:06 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;
	size_t	i;

	tmp_dst = dst;
	tmp_src = (char *)src;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_src[i] == c)
			return (tmp_dst + (i + 1));
		i++;
	}
	return (NULL);
}
