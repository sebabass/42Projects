/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 04:56:07 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/22 02:40:25 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_mapi;
	int		i;

	i = 0;
	if (s && f)
	{
		if (!(str_mapi = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			str_mapi[i] = f(i, s[i]);
			i++;
		}
		str_mapi[i] = '\0';
		return (str_mapi);
	}
	return (NULL);
}
