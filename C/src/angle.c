/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:15:23 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 14:49:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	correct_angle(double incorrect)
{
	double	usable;


	usable = fmod(incorrect + 2 * M_PI, 2 * M_PI);
	return (usable);
}
