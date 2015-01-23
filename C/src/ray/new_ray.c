/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 12:02:16 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 13:30:45 by npineau          ###   ########.fr       */
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
	t_ray	new;

	camera = 2 * x / (double)W_WIDTH - 1;
	new.dir.x = player.dir.x + player.cam.x * camera;
	new.dir.y = player.dir.y + player.cam.y * camera;
	new.map.x = (int)player.pos.x;
	new.map.y = (int)player.pos.y;
	new.delta.x = sqrt(1 + (new.dir.y * new.dir.y) / (new.dir.x * new.dir.x));
	new.delta.y = sqrt(1 + (new.dir.x * new.dir.x) / (new.dir.y * new.dir.y));
	step_side(&new, player);
	return (new);
}
