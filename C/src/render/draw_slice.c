/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 15:09:32 by npineau           #+#    #+#             */
/*   Updated: 2015/01/30 15:26:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	max_down(int const y)
{
	if (y >= W_HEIGHT)
		return (W_HEIGHT - 1);
	return (y);
}

static int	max_up(int const y)
{
	if (y < 0)
		return (0);
	return (y);
}

void		draw_slice(t_img const img,
		t_ray const ray,
		int const x,
		t_player const p)
{
	int		h;
	t_color	wall;
	t_pix	start;
	t_pix	end;

	h = fabs(W_HEIGHT / ray.dist);
	wall = get_wall_color(ray);
	start = new_pixel(new_pos(x, (max_up(-h * (2 - p.pos.z) + W_HEIGHT * p.z) / 2), 0),
			wall);
	end = new_pixel(new_pos(x, max_down((h * p.pos.z + W_HEIGHT * p.z) / 2), 0),
			wall);
	while (start.pos.y <= end.pos.y)
	{
		put_pixel_to_image(img, start);
		++start.pos.y;
	}
}
