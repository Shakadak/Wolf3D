/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:02:45 by npineau           #+#    #+#             */
/*   Updated: 2015/01/26 14:10:38 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	add_option(int const param, int const option)
{
	return (param | option);
}

int	rem_option(int const param, int const option)
{
	return (param & ~option);
}
