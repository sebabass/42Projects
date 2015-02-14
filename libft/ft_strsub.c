/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:48:46 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/07 23:20:27 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	int		size;

	i = 0;
	size = start + len;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (size + 1));
	if (sub)
	{
		while (i < len)
		{
			sub[i] = s[start];
			start++;
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
