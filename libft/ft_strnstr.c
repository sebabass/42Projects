/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:06:06 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/29 04:18:29 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while (s1[i] != '\0' && n >= len)
	{
		if ((s1[i] == s2[0]) && ft_memcmp(&s1[i], s2, len) == 0)
			return ((char *)&s1[i]);
		i++;
		n--;
	}
	return (NULL);
}
