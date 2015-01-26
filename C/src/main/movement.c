/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:55:41 by npineau           #+#    #+#             */
/*   Updated: 2015/01/26 17:12:49 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	forward(t_player *c, t_map const map, double speed)
{
	if (!check(c->pos.x + c->dir.x * speed, c->pos.y, map))
		c->pos.x += c->dir.x * speed;
	if (!check(c->pos.x, c->pos.y + c->dir.y * speed, map))
		c->pos.y += c->dir.y * speed;
	return (2);
}

static int	backward(t_player *c, t_map const map, double speed)
{
	if (!check(c->pos.x - c->dir.x * speed, c->pos.y, map))
		c->pos.x -= c->dir.x * speed;
	if (!check(c->pos.x, c->pos.y - c->dir.y * speed, map))
		c->pos.y -= c->dir.y * speed;
	return (2);
}

int			move(t_env *env, double speed)
{
	if ((env->player.mov & (UP | DOWN)) == UP)
		forward(&env->player, env->map, speed);
	if((env->player.mov & (UP | DOWN)) == DOWN)
		backward(&env->player, env->map, speed);
	if ((env->player.mov & (LEFT | RIGHT)) == LEFT)
		backward(&env->player, env->map, speed);
	if ((env->player.mov & (LEFT | RIGHT)) == RIGHT)
		forward(&env->player, env->map, speed);
	return (0);
}
