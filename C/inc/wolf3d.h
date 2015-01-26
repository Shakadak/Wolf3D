/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:37:48 by npineau           #+#    #+#             */
/*   Updated: 2015/01/26 17:14:42 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>
# include "libft.h"
# include "libumlx.h"

# define W_WIDTH 2400
# define W_HEIGHT 768
# define W_TITLE "Wolf3D"
# define GRAIN 64
# define PLAYER_ORIGIN 2

# define UP 1
# define DOWN 1 << 2
# define LEFT 1 << 3
# define RIGHT 1 << 4

# define CLOCK 1
# define COUNTER 1 << 2

# define SPEED 1.0
# define ROT 1.0

typedef struct		s_dir
{
	double			x;
	double			y;
	double			z;
}					t_dir;

typedef struct		s_map
{
	int				width;
	int				height;
	int				**map;
}					t_map;

typedef struct		s_player
{
	int				mov;
	int				rot;
	t_dir			pos;
	t_dir			dir;
	t_dir			cam;
}					t_player;

typedef struct		s_ray
{
	t_dir			dir;
	t_dir			delta;
	t_dir			side;
	t_pos			map;
	t_pos			step;
	int				where;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	t_win			win;
	t_img			img;
	t_player		player;
	t_map			map;
}					t_env;

int					check(int const col, int const row, t_map const map);
t_ray				dda(t_ray ray, t_map const map);
t_ray				new_ray(t_player const player, int x);
double				get_distance(t_ray const ray, t_player const player);

int					move(t_env *env, double frame);
int					rotate(t_env *env, double frame);
int					is_direction(int key);
void				direction_press(int key, int *mov);
void				direction_release(int key, int *mov);
void				rotation_press(int key, int *rot);
void				rotation_release(int key, int *rot);

t_color				get_wall_color(t_ray const ray);
void				draw_slice(t_img const img,
		t_ray const ray,
		int const x,
		double const distance);

int					add_option(int const param, int const option);
int					rem_option(int const param, int const option);
t_map				get_map(char const *file);
t_player			get_player(t_map const map);
void				hook_init(t_env env);
int					key_hook(int key_code, t_env *env);
int					render(t_env *env);
#endif
