/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 17:38:08 by npineau           #+#    #+#             */
/*   Updated: 2015/01/29 17:38:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		v_rot_press(int key, int *rot)
{
	if (key == XK_Left || key == XK_q)
		*rot = add_option(*rot, ROT_LEFT);
	if (key == XK_Right || key == XK_e)
		*rot = add_option(*rot, ROT_RIGHT);
}

void		v_rot_release(int key, int *rot)
{
	if (key == XK_Left || key == XK_q)
		*rot = rem_option(*rot, ROT_LEFT);
	if (key == XK_Right || key == XK_e)
		*rot = rem_option(*rot, ROT_RIGHT);
}

static void	rot_left(t_player *c, double rot)
{
	double	odirx;
	double	ocamx;

	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(-rot) - c->dir.y * sin(-rot);
	c->dir.y = odirx * sin(-rot) + c->dir.y * cos(-rot);
	c->cam.x = c->cam.x * cos(-rot) - c->cam.y * sin(-rot);
	c->cam.y = ocamx * sin(-rot) + c->cam.y * cos(-rot);
}

static void	rot_right(t_player *c, double rot)
{
	double	odirx;
	double	ocamx;

	odirx = c->dir.x;
	ocamx = c->cam.x;
	c->dir.x = c->dir.x * cos(rot) - c->dir.y * sin(rot);
	c->dir.y = odirx * sin(rot) + c->dir.y * cos(rot);
	c->cam.x = c->cam.x * cos(rot) - c->cam.y * sin(rot);
	c->cam.y = ocamx * sin(rot) + c->cam.y * cos(rot);
}

void		v_rot(t_env *env, double rot)
{
	if ((env->player.rot & (ROT_RIGHT | ROT_LEFT)) == ROT_RIGHT)
		rot_right(&env->player, rot);
	if ((env->player.rot & (ROT_RIGHT | ROT_LEFT)) == ROT_LEFT)
		rot_left(&env->player, rot);
}
