/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:12:33 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/07 23:22:20 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;

	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (join)
	{
		ft_strcpy(join, s1);
		ft_strcat(join, s2);
		return (join);
	}
	return (NULL);
}
