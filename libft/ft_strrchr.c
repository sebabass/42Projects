/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:32:58 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/07 06:27:41 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len_s;

	len_s = ft_strlen(s) - 1;
	while (len_s >= 0)
	{
		if (s[len_s] == c)
			return ((char *)&s[len_s]);
		len_s--;
	}
	return (NULL);
}
