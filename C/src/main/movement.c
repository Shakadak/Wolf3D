/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:55:41 by npineau           #+#    #+#             */
/*   Updated: 2015/01/26 12:11:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define ROT M_PI_4 /4
#define SPEED 0.25

static int	forward(t_player *c, t_map const map)
{
	ft_putendl_fd("UP", 2);
	if (!check(c->pos.x + c->dir.x * SPEED, c->pos.y, map))
		c->pos.x += c->dir.x * SPEED;
	if (!check(c->pos.x, c->pos.y + c->dir.y * SPEED, map))
		c->pos.y += c->dir.y * SPEED;
	return (2);
}

static int	backward(t_player *c, t_map const map)
{
	ft_putendl_fd("DOWN", 2);
	if (!check(c->pos.x - c->dir.x * SPEED, c->pos.y, map))
		c->pos.x -= c->dir.x * SPEED;
	if (!check(c->pos.x, c->pos.y - c->dir.y * SPEED, map))
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
	(key_code == XK_Left ? rot_left(&env->player) : (0));
	(key_code == XK_Right ? rot_right(&env->player) : (0));
	(key_code == XK_Down ? backward(&env->player, env->map) : (0));
	(key_code == XK_Up ? forward(&env->player, env->map) : (0));
	return (0);
}
