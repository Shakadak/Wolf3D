/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_step_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:28:09 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:18:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf3d.h"

void	init_step_dist(t_player *p)
{
	if (p->raydir.x < 0)
	{
		p->step.x = -1;
		p->side.x = (p->raypos.x - p->map.x) * p->delta.x;
	}
	else
	{
		p->step.x = 1;
		p->side.x = (p->map.x + 1.0 - p->raypos.x) * p->delta.x;
	}
	if (p->raydir.y < 0)
	{
		p->step.y = -1;
		p->side.y = (p->raypos.y - p->map.y) * p->delta.y;
	}
	else
	{
		p->step.y = 1;
		p->side.y = (p->map.y + 1.0 - p->raypos.y) * p->delta.y;
	}
}
