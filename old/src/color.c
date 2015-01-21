/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:29:53 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:18:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	color(t_player *play, t_screen *screen)
{
	if (play->raydir.y > 0 && play->orientation == 1)
		SDL_SetRenderDrawColor(screen->r, 175, 175, 0, 255);
	else if (play->raydir.y <= 0 && play->orientation == 1)
		SDL_SetRenderDrawColor(screen->r, 180, 180, 180, 255);
	else if (play->raydir.x <= 0 && play->orientation == 0)
		SDL_SetRenderDrawColor(screen->r, 0, 126, 255, 255);
	else
		SDL_SetRenderDrawColor(screen->r, 255, 0, 0, 255);
}
