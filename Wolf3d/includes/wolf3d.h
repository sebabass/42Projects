/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:52:12 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/18 13:41:23 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH		1250
# define WIN_HEIGHT		960
# define CUBE			50
# define MAP_WIDTH		80
# define MAP_HEIGHT		80
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364
# define ESCAPE			65307
# define RUN_FORWARD	65464
# define RUN_BACK		65458
# define ROTATE_SPEED	0.1
# define MOVE_SPEED		0.2

typedef struct			s_vector
{
	double				x;
	double				y;
}						t_vector;

typedef	struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef	struct			s_map
{
	char				*name;
	int					**tab;
}						t_map;

typedef	struct			s_player
{
	struct s_vector		pos;
	struct s_vector		dir;
	struct s_vector		plane;
	struct s_vector		ray_pos;
	struct s_vector		ray_dir;
	struct s_vector		dist_wall;
	struct s_vector		dist2_wall;
	struct s_pos		tmp_map;
	double				cam_x;
	double				wall_width;
	int					wall_height;
	int					tmp_x;
	int					tmp_y;
	int					is_ver_hor;
	int					color;
	int					secret;
}						t_player;

typedef	struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					sizeline;
	int					bpp;
	int					endian;
	int					cursor;
	struct s_map		map;
	struct s_player		player;
}						t_env;

void					perror_exit(char *error);
void					error_exit(char *error);
int						expose_hook(t_env *e);
int						key_hook(int keycode, t_env *e);
int						open_file(char *path_name);
void					close_file(int const fd);
void					draw(t_env *e);
void					load_map(t_env *e, char *path_map);
void					put_map_console(t_map *map);
void					draw(t_env *e);
void					draw_col_wall(t_env *e, int x);
void					init_player(t_env *e);
void					raycast(t_env *e, t_player *p);
void					rotate_right(t_env *e);
void					rotate_left(t_env *e);
void					move_forward(t_env *e, int speed);
void					move_back(t_env *e, int speed);
void					put_pixel(t_env *e, int x, int y, int color);

#endif
