/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:18:05 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 19:18:38 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	get_distance(t_ray const ray, t_player const player)
{
	if (ray.where == 0)
	{
		return (fabs(((double)ray.map.x - player.pos.x
		+ (1 - (double)ray.step.x) / 2)
		/ ray.dir.x));
	}
	else
	{
		return (fabs(((double)ray.map.y - player.pos.y
		+ (1 - (double)ray.step.y) / 2)
		/ ray.dir.y));
	}
}
