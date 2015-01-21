/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:30:37 by npineau           #+#    #+#             */
/*   Updated: 2014/01/19 16:50:40 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	trace(t_screen *s, t_cam *c, t_player *p, int world[MAPH][MAPW])
{
	int		x;

	x = 0;
	SDL_SetRenderDrawColor(s->r, 0, 0, 0, 255);
	SDL_RenderClear(s->r);
	while (x < WIDTH)
	{
		init_player(c, p, x);
		init_step_dist(p);
		bump(p, world);
		color(p, s);
		draw(line_height(p), s, x);
		x++;
	}
	SDL_RenderPresent(s->r);
}
