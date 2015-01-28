/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:00:18 by npineau           #+#    #+#             */
/*   Updated: 2015/01/28 17:19:35 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		direction_press(int key, int *mov)
{
	if (key == XK_Up || key == XK_w)
		*mov = add_option(*mov, UP);
	if (key == XK_Down || key == XK_s)
		*mov = add_option(*mov, DOWN);
	if (key == XK_a)
		*mov = add_option(*mov, LEFT);
	if (key == XK_d)
		*mov = add_option(*mov, RIGHT);
}

void		direction_release(int key, int *mov)
{
	if (key == XK_Up || key == XK_w)
		*mov = rem_option(*mov, UP);
	if (key == XK_Down || key == XK_s)
		*mov = rem_option(*mov, DOWN);
	if (key == XK_a)
		*mov = rem_option(*mov, LEFT);
	if (key == XK_d)
		*mov = rem_option(*mov, RIGHT);
}
