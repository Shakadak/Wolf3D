/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 17:21:28 by npineau           #+#    #+#             */
/*   Updated: 2015/01/30 16:18:53 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	rot_up(t_player *c, double rot)
{
	c->z += rot;
	if (c->z > 2)
		c->z = 2;
}

static void	rot_down(t_player *c, double rot)
{
	c->z -= rot;
	if (c->z < 0)
		c->z = 0;
}

void		h_rot(t_env *env, double rot)
{
	if ((env->player.rot & (ROT_DOWN | ROT_UP)) == ROT_DOWN)
		rot_down(&env->player, rot);
	if ((env->player.rot & (ROT_DOWN | ROT_UP)) == ROT_UP)
		rot_up(&env->player, rot);
}
