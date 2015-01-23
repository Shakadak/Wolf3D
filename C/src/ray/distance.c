/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:18:05 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 17:28:55 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

double	get_distance(t_ray const ray, t_player const player)
{
	printf("get_distance: rx: %d, ry: %d, px: %f,py: %f\n", ray.map.x, ray.map.y, player.pos.x, player.pos.y);
	if (ray.where == 0)
	{
		return (fabs((ray.map.x - player.pos.x + (1 - ray.step.x) / 2)
					/ ray.dir.x));
	}
	else
	{
		return (fabs((ray.map.y - player.pos.y + (1 - ray.step.y) / 2)
					/ ray.dir.y));
	}
}
