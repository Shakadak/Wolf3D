/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 15:47:19 by npineau           #+#    #+#             */
/*   Updated: 2015/03/23 17:07:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color	get_wall_color(t_ray const ray)
{
	if (ray.dir.y > 0 && ray.where == 1)
		return (new_color(0, 175, 175, 0));
	else if (ray.dir.y <= 0 && ray.where == 1)
		return (new_color(180, 180, 180, 0));
	else if (ray.dir.x <= 0 && ray.where == 0)
		return (new_color(255, 126, 0, 0));
	else
		return (new_color(0, 0, 255, 0));
}
