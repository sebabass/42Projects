/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 13:52:28 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/16 16:29:00 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 1330
# define WIN_WIDTH 	2400
# define Z_UP_MAX	5
# define Z_DWN_MAX	-10
# define Z_BASE		0.5
# define ZOOM_MAX	10
# define ZOOM_MIN	0
# define ZOOM_BASE	5

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*av;
	int				fd;
	int				n_point_line;
	int				n_line;
	int				pad_line;
	int				bpp;
	int				endian;
	int				zoom;
	int				is_help;
	int				is_color;
	int				is_file;
	int				color_t;
	float			x1;
	float			y1;
	float			z1;
	struct s_point	***map;
}					t_env;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

int					expose_hook(t_env *e);
int					key_press(int keycode, t_env *e);
int					key_release(int keycode, t_env *e);
int					get_color_theme(t_env *e, t_point *p1, t_point *p2);
void				create_map_point(t_env *e, char *l, char **split, char *li);
void				change_map(t_env *e);
void				put_map(t_env *e, int x, int y);
void				move(t_env *e, int c, float value);
void				zoom(t_env *e, int value, int zm);
void				activate(t_env *e, int kc);
void				reset(t_env *e);
void				free_map(t_env *e, int i, int j);
void				draw(t_env *e);
void				change_color_theme(t_env *e, int kc);
void				put_menu_help(t_env *e);
void				put_menu_color_theme(t_env *e);
void				put_menu_file(t_env *e);

#endif
