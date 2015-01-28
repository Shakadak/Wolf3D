/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 12:02:16 by npineau           #+#    #+#             */
/*   Updated: 2015/01/28 16:05:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		step_side(t_ray *ray, t_player const p)
{
	ray->step.x = (ray->dir.x < 0) ? -1 : 1;
	ray->side.x = (ray->dir.x < 0) ? (p.pos.x - ray->map.x) * ray->delta.x
		: (ray->map.x + 1 - p.pos.x) * ray->delta.x;
	ray->step.y = (ray->dir.y < 0) ? -1 : 1;
	ray->side.y = (ray->dir.y < 0) ? (p.pos.y - ray->map.y) * ray->delta.y
		: (ray->map.y + 1 - p.pos.y) * ray->delta.y;
}

t_ray			new_ray(t_player const player, int x)
{
	double	camera;
	t_ray	ray;

	camera = 2 * (double)x / W_WIDTH - 1;
	ray.dir.x = player.dir.x + player.cam.x * camera;
	ray.dir.y = player.dir.y + player.cam.y * camera;
	ray.map.x = (int)player.pos.x;
	ray.map.y = (int)player.pos.y;
	ray.delta.x = sqrt(1 + (ray.dir.y * ray.dir.y) / (ray.dir.x * ray.dir.x));
	ray.delta.y = sqrt(1 + (ray.dir.x * ray.dir.x) / (ray.dir.y * ray.dir.y));
	step_side(&ray, player);
	ray.dist = 0.0;
	return (ray);
}
