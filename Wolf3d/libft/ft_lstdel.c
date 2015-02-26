/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 11:14:35 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/29 11:27:24 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		while (*alst)
		{
			if ((*alst)->content)
				del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
		}
		ft_memdel((void **)alst);
	}
}
