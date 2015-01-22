/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:36:25 by npineau           #+#    #+#             */
/*   Updated: 2014/01/19 18:43:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# include "SDL.h"
# define WOLF_H
# define MAPW	23
# define MAPH	23
# define WIDTH	640
# define HEIGHT	480

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
	SDL_Window		*w;
	SDL_Renderer	*r;
}					t_screen;

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
