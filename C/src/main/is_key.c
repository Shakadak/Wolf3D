/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:19:28 by npineau           #+#    #+#             */
/*   Updated: 2015/01/29 17:35:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			is_direction(int key)
{
	return (key == XK_Up || key == XK_w
	|| key == XK_Down || key == XK_s
	|| key == XK_d
	|| key == XK_a);
}

int			is_vertical_rotation(int key)
{
	return (key == XK_Left || key == XK_q
	|| key == XK_Right || key == XK_e);
}

int	is_horizontal_rotation(int key)
{
	return (key == XK_r || key == XK_f);
}
