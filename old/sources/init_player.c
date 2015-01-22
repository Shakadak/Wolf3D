/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:27:27 by npineau           #+#    #+#             */
/*   Updated: 2014/01/19 16:49:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf.h"

void	init_player(t_cam *c, t_player *p, int x)
{
	p->camera = 2 * (double)x / (double)WIDTH - 1;
	p->raypos.x = c->pos.x;
	p->raypos.y = c->pos.y;
	p->raydir.x = c->dir.x + c->plane.x * p->camera;
	p->raydir.y = c->dir.y + c->plane.y * p->camera;
	p->map.x = (int)p->raypos.x;
	p->map.y = (int)p->raypos.y;
	p->delta.x = sqrt(1 + (p->raydir.y * p->raydir.y)
			/ (p->raydir.x * p->raydir.x));
	p->delta.y = sqrt(1 + (p->raydir.x * p->raydir.x)
			/ (p->raydir.y * p->raydir.y));
	p->hit = 0;
}
