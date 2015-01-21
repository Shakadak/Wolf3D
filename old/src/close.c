/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:27:06 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:18:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	close(t_screen *screen)
{
	SDL_DestroyRenderer(screen->r);
	SDL_DestroyWindow(screen->w);
	SDL_Quit();
}
