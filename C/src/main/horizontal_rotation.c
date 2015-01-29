/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 17:21:28 by npineau           #+#    #+#             */
/*   Updated: 2015/01/29 17:39:38 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		h_rot_press(int key, int *rot)
{
	if (key == XK_r)
		*rot = add_option(*rot, ROT_UP);
	if (key == XK_f)
		*rot = add_option(*rot, ROT_DOWN);
}

void		h_rot_release(int key, int *rot)
{
	if (key == XK_r)
		*rot = rem_option(*rot, ROT_UP);
	if (key == XK_f)
		*rot = rem_option(*rot, ROT_DOWN);
}

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
