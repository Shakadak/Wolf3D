/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:15:23 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 11:15:40 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	correct_angle(double incorrect)
{
	int		mod;
	double	usable;

	mod = (2 * M_PI) * (1 << 8);
	usable = ((int)((incorrect + 2 * M_PI) * (1 << 8)) % mod) / (1 << 8);
	return (usable);
}
