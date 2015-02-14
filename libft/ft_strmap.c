/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 04:24:37 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/07 23:21:22 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_map;
	int		i;

	i = 0;
	if (s)
	{
		if (f)
		{
			str_map = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
			while (s[i] != '\0')
			{
				str_map[i] = f(s[i]);
				i++;
			}
			str_map[i] = '\0';
			return (str_map);
		}
		return (NULL);
	}
	return (NULL);
}
