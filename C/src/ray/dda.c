/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:31:48 by npineau           #+#    #+#             */
/*   Updated: 2015/01/27 12:56:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ray	dda(t_ray ray, t_map const map)
{
	while (!check(ray.map.x, ray.map.y, map))
	{
		if (ray.side.x < ray.side.y)
		{
			ray.side.x += ray.delta.x;
			ray.map.x += ray.step.x;
			ray.where = 0;
		}
		else
		{
			ray.side.y += ray.delta.y;
			ray.map.y += ray.step.y;
			ray.where = 1;
		}
	}
	return (ray);
}
