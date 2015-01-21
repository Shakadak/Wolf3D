/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:26:30 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:18:30 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define SDLWP	SDL_WINDOWPOS_UNDEFINED
#define SDLF	SDL_WINDOW_SHOWN

void	init(t_screen *screen)
{
	SDL_Init(SDL_INIT_VIDEO);
	screen->w = SDL_CreateWindow("Wolf3D", SDLWP, SDLWP, WIDTH, HEIGHT, SDLF);
	screen->r = SDL_CreateRenderer(screen->w, -1, SDL_RENDERER_ACCELERATED);
}
