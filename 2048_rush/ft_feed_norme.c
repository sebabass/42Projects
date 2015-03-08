/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feed_norme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:44:40 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/01 18:57:55 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "game.h"

static	void		ft_key_up_coco(t_game *game)
{
	ft_key_type(game, UP);
	if ((ft_fusion(game, UP)) > 0)
		ft_key_type(game, UP);
}

static	void		ft_key_down_coco(t_game *game)
{
	ft_key_type(game, DOWN);
	if ((ft_fusion(game, DOWN)) > 0)
		ft_key_type(game, DOWN);
}

static	void		ft_key_left_coco(t_game *game)
{
	ft_key_type(game, LEFT);
	if ((ft_fusion(game, LEFT)) > 0)
		ft_key_type(game, LEFT);
}

static	void		ft_key_right_coco(t_game *game)
{
	ft_key_type(game, RIGHT);
	if ((ft_fusion(game, RIGHT)) > 0)
		ft_key_type(game, RIGHT);
}

void				ft_feed_norme(t_game *game)
{
	if (game->c == KEY_UP)
		ft_key_up_coco(game);
	if (game->c == KEY_DOWN)
		ft_key_down_coco(game);
	if (game->c == KEY_RIGHT)
		ft_key_right_coco(game);
	if (game->c == KEY_LEFT)
		ft_key_left_coco(game);
}
