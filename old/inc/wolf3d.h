/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:36:25 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:25:49 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# include <SDL2/SDL.h>

# define WOLF3D_H
# define MAPW	23
# define MAPH	23
# define WIDTH	640
# define HEIGHT	480

# include <math.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "libft.h"

# define W_WIDTH 1366
# define W_HEIGHT 768
# define W_TITLE "Wolf3D"
# define GRAIN 64
# define PLAYER_ORIGIN 2

typedef struct	s_coo
{
	double		x;
	double		y;
}				t_coo;

typedef struct	s_ico
{
	int			x;
	int			y;
}				t_ico;

typedef struct	s_cam
{
	t_coo		pos;
	t_coo		dir;
	t_coo		plane;
	double		time;
	double		oldtime;
}				t_cam;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef union		u_color
{
	unsigned int	id;
	unsigned char	rgb[4];
}					t_color;

typedef struct		s_pixel
{
	t_point			coordinate;
	t_color			color;
}					t_pixel;

typedef struct		s_map
{
	int				width;
	int				height;
	char			**map;
}					t_map;

typedef struct	s_player
{
	t_ico		map;
	t_coo		side;
	t_coo		delta;
	double		wall;
	double		camera;
	t_coo		raypos;
	t_coo		raydir;
	t_ico		step;
	int			hit;
	int			orientation;
}				t_player;

typedef struct		s_screen
{
	void			*w;
	void			*r;
}					t_screen;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bits;
	int				lsize;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_player		player;
	t_map			map;
}					t_env;

void	raycast(int world[MAPH][MAPW]);
void	bump(t_player *p, int world[MAPH][MAPW]);
void	close(t_screen *s);
void	color(t_player *p, t_screen *s);
void	draw(t_ico draw, t_screen *s, int x);
void	init(t_screen *s);
void	init_player(t_cam *c, t_player *p, int x);
void	init_step_dist(t_player *p);
t_ico	line_height(t_player *p);
int		move(t_cam *c, int world[MAPH][MAPW]);
void	trace(t_screen *s, t_cam *c, t_player *p, int world[MAPH][MAPW]);

#endif
