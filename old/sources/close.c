/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:27:06 by npineau           #+#    #+#             */
/*   Updated: 2014/01/19 16:49:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "SDL.h"

void	close(t_screen *screen)
{
	SDL_DestroyRenderer(screen->r);
	SDL_DestroyWindow(screen->w);
	SDL_Quit();
}
