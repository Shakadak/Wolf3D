/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:55:41 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 17:55:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define ROT 0.1
#define SPEED 0.25


static int	forward(t_player *c, int **world)
{
	if (world[(int)(c->pos.x + c->dir.x * SPEED)][(int)c->pos.y] == 0)
		c->pos.x += c->dir.x * SPEED;
	if (world[(int)c->pos.x][(int)(c->pos.y + c->dir.y * SPEED)] == 0)
		c->pos.y += c->dir.y *SPEED;
	return (2);
}

static int	backward(t_player *c, int **world)
{
	if (world[(int)(c->pos.x - c->dir.x * SPEED)][(int)c->pos.y] == 0)
		c->pos.x -= c->dir.x * SPEED;
	if (world[(int)c->pos.x][(int)(c->pos.y - c->dir.y * SPEED)] == 0)
		c->pos.y -= c->dir.y * SPEED;
	return (2);
}

static int	rot_left(t_player *c)
{
	double	odirx;
	double	ocamx;
	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(-ROT) - c->dir.y * sin(-ROT);
	c->dir.y = odirx * sin(-ROT) + c->dir.y * cos(-ROT);
	c->cam.x = c->cam.x * cos(-ROT) - c->cam.y * sin(-ROT);
	c->cam.y = ocamx * sin(-ROT) + c->cam.y * cos(-ROT);
	return (2);
}
static int	rot_right(t_player *c)
{
	double	odirx;
	double	ocamx;
	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(ROT) - c->dir.y * sin(ROT);
	c->dir.y = odirx * sin(ROT) + c->dir.y * cos(ROT);
	c->cam.x = c->cam.x * cos(ROT) - c->cam.y * sin(ROT);
	c->cam.y = ocamx * sin(ROT) + c->cam.y * cos(ROT);
	return (2);
}

int			move(int key_code, t_env *env)
{
	(key_code == XK_Left ? rot_right(&env->player) : (0));
	(key_code == XK_Right ? rot_left(&env->player) : (0));
	(key_code == XK_Down ? backward(&env->player, env->map.map) :  (0));
	(key_code == XK_Up ? forward(&env->player, env->map.map) : (0));
	return (0);
}
