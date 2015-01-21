/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:30:15 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:18:26 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw(t_ico draw, t_screen *screen, int x)
{
	while (draw.x <= draw.y)
	{
		SDL_RenderDrawPoint(screen->r, x, draw.x);
		draw.x++;
	}
}
