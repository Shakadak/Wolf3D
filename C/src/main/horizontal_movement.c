/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:55:41 by npineau           #+#    #+#             */
/*   Updated: 2015/02/03 13:38:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	rightward(t_player *c, t_map const map, double speed)
{
	if (!collide(c->pos.x + -c->dir.y * speed, c->pos.y, map))
		c->pos.x += -c->dir.y * speed;
	if (!collide(c->pos.x, c->pos.y + c->dir.x * speed, map))
		c->pos.y += c->dir.x * speed;
}

static void	leftward(t_player *c, t_map const map, double speed)
{
	if (!collide(c->pos.x + c->dir.y * speed, c->pos.y, map))
		c->pos.x += c->dir.y * speed;
	if (!collide(c->pos.x, c->pos.y + -c->dir.x * speed, map))
		c->pos.y += -c->dir.x * speed;
}

static void	forward(t_player *c, t_map const map, double speed)
{
	if (!collide(c->pos.x + c->dir.x * speed, c->pos.y, map))
		c->pos.x += c->dir.x * speed;
	if (!collide(c->pos.x, c->pos.y + c->dir.y * speed, map))
		c->pos.y += c->dir.y * speed;
}

static void	backward(t_player *c, t_map const map, double speed)
{
	if (!collide(c->pos.x - c->dir.x * speed, c->pos.y, map))
		c->pos.x -= c->dir.x * speed;
	if (!collide(c->pos.x, c->pos.y - c->dir.y * speed, map))
		c->pos.y -= c->dir.y * speed;
}

void		move(t_env *env, double speed)
{
	if ((env->player.mov & SPRINT) == SPRINT)
		speed *= 2;
	if ((env->player.mov & (FORWARD | BACKWARD)) == FORWARD)
		forward(&env->player, env->map, speed);
	if ((env->player.mov & (FORWARD | BACKWARD)) == BACKWARD)
		backward(&env->player, env->map, speed);
	if ((env->player.mov & (LEFT | RIGHT)) == LEFT)
		leftward(&env->player, env->map, speed);
	if ((env->player.mov & (LEFT | RIGHT)) == RIGHT)
		rightward(&env->player, env->map, speed);
	v_mov(env, speed);
}
