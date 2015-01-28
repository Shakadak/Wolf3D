/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:55:41 by npineau           #+#    #+#             */
/*   Updated: 2015/01/28 15:03:48 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	rightward(t_player *c, t_map const map, double speed)
{
	if (!check(c->pos.x + -c->dir.y * speed, c->pos.y, map))
		c->pos.x += -c->dir.y * speed;
	if (!check(c->pos.x, c->pos.y + c->dir.x * speed, map))
		c->pos.y += c->dir.x * speed;
}

static void	leftward(t_player *c, t_map const map, double speed)
{
	if (!check(c->pos.x + c->dir.y * speed, c->pos.y, map))
		c->pos.x += c->dir.y * speed;
	if (!check(c->pos.x, c->pos.y + -c->dir.x * speed, map))
		c->pos.y += -c->dir.x * speed;
}

static void	forward(t_player *c, t_map const map, double speed)
{
	if (!check(c->pos.x + c->dir.x * speed, c->pos.y, map))
		c->pos.x += c->dir.x * speed;
	if (!check(c->pos.x, c->pos.y + c->dir.y * speed, map))
		c->pos.y += c->dir.y * speed;
}

static void	backward(t_player *c, t_map const map, double speed)
{
	if (!check(c->pos.x - c->dir.x * speed, c->pos.y, map))
		c->pos.x -= c->dir.x * speed;
	if (!check(c->pos.x, c->pos.y - c->dir.y * speed, map))
		c->pos.y -= c->dir.y * speed;
}

void		move(t_env *env, double speed)
{
	if ((env->player.mov & (UP | DOWN)) == UP)
		forward(&env->player, env->map, speed);
	if((env->player.mov & (UP | DOWN)) == DOWN)
		backward(&env->player, env->map, speed);
	if ((env->player.mov & (LEFT | RIGHT)) == LEFT)
		leftward(&env->player, env->map, speed);
	if ((env->player.mov & (LEFT | RIGHT)) == RIGHT)
		rightward(&env->player, env->map, speed);
}
