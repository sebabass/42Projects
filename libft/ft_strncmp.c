/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 03:54:00 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/09 02:03:25 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static	int	v_str_ascii(const char *str, size_t n)
{
	size_t	i;
	int		v_ascii;

	i = 0;
	v_ascii = 0;
	while (i < n)
	{
		v_ascii += str[i];
		i++;
	}
	return (v_ascii);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		s1_ascii;
	int		s2_ascii;

	s1_ascii = v_str_ascii(s1, n);
	s2_ascii = v_str_ascii(s2, n);
	if (n == 0)
		return (0);
	if (s1_ascii < s2_ascii)
		return ((s1_ascii - s2_ascii));
	else if (s1_ascii == s2_ascii)
	{
		if (s1[0] > s2[0])
			return (1);
		if (s1[0] < s2[0])
			return (-1);
		return (0);
	}
	else
		return ((s1_ascii - s2_ascii));
}
