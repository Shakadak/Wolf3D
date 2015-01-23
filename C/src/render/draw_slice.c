/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 15:09:32 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 17:03:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_slice(t_img const img,
		t_ray const ray,
		int const x,
		int const distance)
{
	int		height;
	t_color	wall;
	t_pix	start;
	t_pix	end;

	height = fabs(W_HEIGHT / distance);
	wall = get_wall_color(ray);
	start = new_pixel(new_pos(x, (-height + W_HEIGHT) / 2, 0), wall);
	end = new_pixel(new_pos(x, (height + W_HEIGHT) / 2, 0), wall);
	draw_line(img, start, end);
}
