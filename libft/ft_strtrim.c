/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:44:21 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/09 04:26:47 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static	int	is_whitespace(int c)
{
	if (c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\t')
		return (1);
	return (0);
}

static	int	trim_end(char const *s)
{
	int		end;

	end = ft_strlen(s);
	if (end > 0)
	{
		while (is_whitespace(s[end - 1]))
		{
			if (end == 0)
				return (end);
			end--;
		}
	}
	return (end);
}

static	int	trim_start(char const *s)
{
	int		start;

	start = 0;
	while (s[start] != 0)
	{
		if (!is_whitespace(s[start]))
			return (start);
		start++;
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = trim_start(s);
	end = trim_end(s);
	i = (end - start);
	trim = (char *)malloc(sizeof(trim) * (i + 1));
	if (trim)
	{
		trim = ft_strsub(s, start, i);
		return (trim);
	}
	return (NULL);
}
