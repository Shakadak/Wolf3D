/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 18:09:24 by npineau           #+#    #+#             */
/*   Updated: 2015/02/03 13:41:28 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	h_mov_release(int key, int *mov)
{
	if (key == XK_Up || key == XK_w)
		*mov = rem_option(*mov, FORWARD);
	if (key == XK_Down || key == XK_s)
		*mov = rem_option(*mov, BACKWARD);
	if (key == XK_a)
		*mov = rem_option(*mov, LEFT);
	if (key == XK_d)
		*mov = rem_option(*mov, RIGHT);
	if (key == XK_Shift_L)
		*mov = rem_option(*mov, SPRINT);
}

void	v_mov_release(int key, int *mov)
{
	if (key == XK_t)
		*mov = rem_option(*mov, UP);
	if (key == XK_g)
		*mov = rem_option(*mov, DOWN);
}

void	h_rot_release(int key, int *rot)
{
	if (key == XK_r)
		*rot = rem_option(*rot, ROT_UP);
	if (key == XK_f)
		*rot = rem_option(*rot, ROT_DOWN);
}

void	v_rot_release(int key, int *rot)
{
	if (key == XK_Left || key == XK_q)
		*rot = rem_option(*rot, ROT_LEFT);
	if (key == XK_Right || key == XK_e)
		*rot = rem_option(*rot, ROT_RIGHT);
}
