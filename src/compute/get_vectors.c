/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:11:50 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/07 14:52:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

void	get_direction_vector(float angle, double *dx, double *dy)
{
	*dx = cosf(angle);
	*dy = sinf(angle);
}

void	get_perpendicular_vector(float angle, float *dx, float *dy)
{
	*dx = cosf(angle + (M_PI / 2));
	*dy = sinf(angle + (M_PI / 2));
}
