/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:29:14 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:52:41 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** draw.x is equivalent to column.start
** draw.y is equivalent to column.end
*/

t_ico	line_height(t_player *p)
{
	t_ico	draw;
	int		line_h;

	if (p->orientation == 0)
		p->wall = fabs((p->map.x - p->raypos.x + (1 - p->step.x)
					/ 2) / p->raydir.x);
	else
		p->wall = fabs((p->map.y - p->raypos.y + (1 - p->step.y)
					/ 2) / p->raydir.y);
	line_h = (int)(W_HEIGHT / p->wall);
	draw.x = -line_h / 2 + W_HEIGHT / 2;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = line_h / 2 + W_HEIGHT / 2;
	if (draw.y >= W_HEIGHT)
		draw.y = W_HEIGHT - 1;
	return (draw);
}
