/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:22:26 by npineau           #+#    #+#             */
/*   Updated: 2015/01/22 11:22:31 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void	*new_window(void *mlx, int width, int height, char *title)
{
	t_win	win;

	win.win = mlx_new_window(mlx, width, height, title);
	if (win == NULL)
		ft_fatal("mlx_new_window", 1);
	win.width = width;
	win.height = height;
	win.title = title;
	return (win);
}
