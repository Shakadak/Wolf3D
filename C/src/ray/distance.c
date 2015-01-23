/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:18:05 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 13:24:01 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	distance(t_ray const ray, t_player const player)
{
	if (ray.where == 0)
	{
		return (fabs((ray.map.x - player.pos.x + (1 - ray.step.x) / 2)
					/ ray.dir.x));
	}
	else
	{
		return (fabs((ray.map.x - player.pos.x + (1 - ray.step.x) / 2)
					/ ray.dir.x));
	}
}
