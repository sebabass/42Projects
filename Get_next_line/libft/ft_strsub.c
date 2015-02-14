/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:48:46 by spariaud          #+#    #+#             */
/*   Updated: 2014/12/28 20:47:37 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((sub = ft_strnew(len + 1)))
	{
		while (i < len && s[start])
		{
			sub[i] = s[start];
			start++;
			i++;
		}
		return (ft_strdup(sub));
	}
	return (NULL);
}
