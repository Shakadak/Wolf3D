/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:42:08 by npineau           #+#    #+#             */
/*   Updated: 2015/01/19 17:41:06 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	*init(void)
{
	return (mlx_init());
}

void	*new_window(void *env)
{
	return (mlx_new_window(env, W_WIDTH, W_HEIGHT, W_TITLE));
}
