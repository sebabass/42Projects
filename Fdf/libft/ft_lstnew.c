/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 05:07:17 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/29 06:17:34 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(cont = (void *)malloc(content_size)))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		cont = ft_memcpy(cont, content, content_size);
		new->content = cont;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
