/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 00:35:08 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/07 09:04:11 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * n);
	ft_strncpy(tmp, src, n);
	dst = (void *)ft_strncpy(dst, tmp, n);
	free(tmp);
	return (dst);
}
