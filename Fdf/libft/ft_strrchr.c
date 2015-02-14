/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:32:58 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/12 20:02:09 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len_s;

	len_s = ft_strlen(s);
	if (c < 0)
		return (NULL);
	while (len_s >= 0)
	{
		if (s[len_s] == c)
			return ((char *)&s[len_s]);
		len_s--;
	}
	if (s[len_s] == c)
		return ((char *)&s[len_s]);
	else
		return (NULL);
}
