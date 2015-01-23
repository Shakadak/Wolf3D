/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:59:15 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 12:55:58 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "wolf3d.h"


int		correct_height(int incorrect)
{
	if (incorrect > W_HEIGHT)
		return(W_HEIGHT);
	if (incorrect < 0)
		return (0);
	return (incorrect);
}

int		render(t_env *env)
{
	(void)env;
	usleep(1000000 / 60);
	return (1);
}
