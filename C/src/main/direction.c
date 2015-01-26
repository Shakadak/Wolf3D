/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:00:18 by npineau           #+#    #+#             */
/*   Updated: 2015/01/26 14:10:12 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			is_direction(int key)
{
	return (key == XK_Up || key == XK_w
	|| key == XK_Down || key == XK_s
	|| key == XK_q
	|| key == XK_e);
}

void		direction_press(int key, int *mov)
{
	if (key == XK_Up || key == XK_w)
		*mov = add_option(*mov, UP);
	if (key == XK_Down || key == XK_s)
		*mov = add_option(*mov, DOWN);
	if (key == XK_q)
		*mov = add_option(*mov, LEFT);
	if (key == XK_e)
		*mov = add_option(*mov, RIGHT);
}

void		direction_release(int key, int *mov)
{
	if (key == XK_Up || key == XK_w)
		*mov = rem_option(*mov, UP);
	if (key == XK_Down || key == XK_s)
		*mov = rem_option(*mov, DOWN);
	if (key == XK_q)
		*mov = rem_option(*mov, LEFT);
	if (key == XK_e)
		*mov = rem_option(*mov, RIGHT);
}
