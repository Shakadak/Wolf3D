/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:37:48 by npineau           #+#    #+#             */
/*   Updated: 2015/03/23 16:40:14 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "libumlx.h"

# define KeyPress	2
# define KeyRelease	3
# define KeyPressMask	(1L<<0)
# define KeyReleaseMask	(1L<<1)

# define XK_Escape 53

# define XK_Left 123
# define XK_Right 124
# define XK_Down 125
# define XK_Up 126

# define XK_w 13
# define XK_a 0
# define XK_s 1
# define XK_d 2
# define XK_q 12
# define XK_e 14

# define XK_r 15
# define XK_f 3
# define XK_t 17
# define XK_g 5

# define XK_Shift_L 257
# define XK_Ctrl_L 258
# define XK_Space 49

# define XK_1 18

# define W_WIDTH 1366
# define W_HEIGHT 768
# define W_TITLE "Wolf3D"
# define GRAIN 64
# define PLAYER_ORIGIN 2

# define UP 1
# define DOWN 1 << 1
# define LEFT 1 << 2
# define RIGHT 1 << 3
# define FORWARD 1 << 4
# define BACKWARD 1 << 5
# define SPRINT 1 << 6

# define ROT_RIGHT 1
# define ROT_LEFT 1 << 1
# define ROT_UP 1 << 2
# define ROT_DOWN 1 << 3

# define SPEED 2.0
# define ROT 2.0
# define HITBOX 0.1 * W_HEIGHT / W_WIDTH

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
	double			dist;
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

int					collide(double const x, double const y, t_map const map);
int					check(int const col, int const row, t_map const map);
t_ray				dda(t_ray ray, t_map const map);
t_ray				new_ray(t_player const player, int x);
double				get_distance(t_ray const ray, t_player const player);
double				get_frame_time(void);

void				move(t_env *env, double frame);

void				h_mov_press(int key, int *mov);
void				h_mov_release(int key, int *mov);

void				v_mov_press(int key, int *mov);
void				v_mov_release(int key, int *mov);
void				v_mov(t_env *env, double speed);

void				rotate(t_env *env, double frame);

void				v_rot_press(int key, int *rot);
void				v_rot_release(int key, int *rot);
void				v_rot(t_env *env, double rot);

void				h_rot_press(int key, int *rot);
void				h_rot_release(int key, int *rot);
void				h_rot(t_env *env, double rot);

t_color				get_wall_color(t_ray const ray);
void				draw_slice(t_img const img,
		t_ray const ray,
		int const x,
		t_player const player);

int					add_option(int const param, int const option);
int					rem_option(int const param, int const option);
t_map				get_map(char const *file);
t_player			get_player(t_map const map);
void				hook_init(t_env const *env);
int					key_hook(int key_code, t_env *env);
int					render(t_env *env);
#endif
