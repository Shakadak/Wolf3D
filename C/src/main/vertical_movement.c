/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:17:20 by npineau           #+#    #+#             */
/*   Updated: 2015/01/30 17:06:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	upward(t_player *c, double speed)
{
	c->pos.z += speed;
	if (c->pos.z > 1.99)
		c->pos.z = 1.99;
}

static void	downward(t_player *c, double speed)
{
	c->pos.z -= speed;
	if (c->pos.z < 0.01)
		c->pos.z = 0.01;
}

void		v_mov(t_env *env, double speed)
{
	if ((env->player.mov & (DOWN | UP)) == UP)
		upward(&env->player, speed);
	if ((env->player.mov & (DOWN | UP)) == DOWN)
		downward(&env->player, speed);
}
