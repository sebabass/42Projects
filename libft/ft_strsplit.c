/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:40:22 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/12 00:10:52 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static	int	lenstr_n(char const *s, int start, char c)
{
	int		i;

	i = 0;
	while (s[start] != c)
	{
		if (s[start] == '\0')
			return (i);
		i++;
		start++;
	}
	return (i);
}

static	int	nbrstr(char const *s, char c)
{
	int		i;
	int		nbr_str;

	i = 0;
	nbr_str = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nbr_str++;
			i += lenstr_n(s, i, c);
		}
		else
			i++;
	}
	return (nbr_str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(char *) * (nbrstr(s, c) + 1))))
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
			{
				tab[j++] = ft_strsub(s, (unsigned int)i, lenstr_n(s, i, c));
				i += lenstr_n(s, i, c);
			}
			else
				i++;
		}
		tab[j] = "\0";
		return (tab);
	}
	return (NULL);
}
