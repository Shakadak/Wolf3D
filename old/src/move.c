/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 20:36:22 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:19:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

#define ROT 0.1
#define SPEED 0.25

static int		forward(t_cam *c, int world[MAPH][MAPW]);
static int		backward(t_cam *c, int world[MAPH][MAPW]);
static int		rot_right(t_cam *c);
static int		rot_left(t_cam *c);

int				move(t_cam *c, int world[MAPH][MAPW])
{
	int			mod;
	SDL_Event	ev;

	mod = 1;
	while (SDL_PollEvent(&ev) != 0)
	{
		if (ev.key.keysym.sym == SDLK_ESCAPE)
			mod = 0;
		if (ev.key.keysym.sym == SDLK_UP && ev.key.type == SDL_KEYDOWN)
			mod = forward(c, world);
		if (ev.key.keysym.sym == SDLK_DOWN && ev.key.type == SDL_KEYDOWN)
			mod = backward(c, world);
		if (ev.key.keysym.sym == SDLK_LEFT && ev.key.type == SDL_KEYDOWN)
			mod = rot_left(c);
		if (ev.key.keysym.sym == SDLK_RIGHT && ev.key.type == SDL_KEYDOWN)
			mod = rot_right(c);
	}
	return (mod);
}

static int		forward(t_cam *c, int world[MAPH][MAPW])
{
	if (world[(int)(c->pos.x + c->dir.x * SPEED)][(int)c->pos.y] == 0)
		c->pos.x += c->dir.x * SPEED;
	if (world[(int)c->pos.x][(int)(c->pos.y + c->dir.y * SPEED)] == 0)
		c->pos.y += c->dir.y *SPEED;
	return (2);
}

static int		backward(t_cam *c, int world[MAPH][MAPW])
{
	if (world[(int)(c->pos.x - c->dir.x * SPEED)][(int)c->pos.y] == 0)
		c->pos.x -= c->dir.x * SPEED;
	if (world[(int)c->pos.x][(int)(c->pos.y - c->dir.y * SPEED)] == 0)
		c->pos.y -= c->dir.y * SPEED;
	return (2);
}

static int		rot_left(t_cam *c)
{
	double		odirx;
	double		oplanex;

	odirx = c->dir.x;
	oplanex = c->plane.x;
	c->dir.x = c->dir.x * cos(-ROT) - c->dir.y * sin(-ROT);
	c->dir.y = odirx * sin(-ROT) + c->dir.y * cos(-ROT);
	c->plane.x = c->plane.x * cos(-ROT) - c->plane.y * sin(-ROT);
	c->plane.y = oplanex * sin(-ROT) + c->plane.y * cos(-ROT);
	return (2);
}

static int		rot_right(t_cam *c)
{
	double		odirx;
	double		oplanex;

	odirx = c->dir.x;
	oplanex = c->plane.x;
	c->dir.x = c->dir.x * cos(ROT) - c->dir.y * sin(ROT);
	c->dir.y = odirx * sin(ROT) + c->dir.y * cos(ROT);
	c->plane.x = c->plane.x * cos(ROT) - c->plane.y * sin(ROT);
	c->plane.y = oplanex * sin(ROT) + c->plane.y * cos(ROT);
	return (2);
}
