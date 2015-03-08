/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 01:18:34 by spariaud          #+#    #+#             */
/*   Updated: 2014/12/28 20:03:00 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (void *)s;
	i = 0;
	if (s && n > 0)
	{
		while (i < n)
		{
			if (tmp[i] == (char)c)
				return (&tmp[i]);
			i++;
		}
	}
	return (NULL);
}
