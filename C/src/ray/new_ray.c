/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 12:02:16 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 12:53:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		step_side(t_ray *ray, t_dir const raydir, t_player const p)
{
	ray->step.x = (raydir.x < 0) ? -1 : 1;
	ray->side.x = (raydir.x < 0) ? (p.pos.x - ray->map.x) * ray->delta.x
		: (ray->map.x + 1 - p.pos.x) * ray->delta.x;
	ray->step.y = (raydir.y < 0) ? -1 : 1;
	ray->side.y = (raydir.y < 0) ? (p.pos.y - ray->map.y) * ray->delta.y
		: (ray->map.y + 1 - p.pos.y) * ray->delta.y;
}

t_ray			new_ray(t_player const player, int x)
{
	double	camera;
	t_dir	raydir;
	t_ray	new;

	camera = 2 * x / (double)W_WIDTH - 1;
	raydir.x = player.dir.x + player.cam.x * camera;
	raydir.y = player.dir.y + player.cam.y * camera;
	new.map.x = (int)player.pos.x;
	new.map.y = (int)player.pos.y;
	new.delta.x = sqrt(1 + (raydir.y * raydir.y) / (raydir.x * raydir.x));
	new.delta.y = sqrt(1 + (raydir.x * raydir.x) / (raydir.y * raydir.y));
	step_side(&new, raydir, player);
	return (new);
}
