/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:45:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 09:52:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/raycaster.h"

float	compute_first_boundary_x(t_dda *d)
{
	float	boundary_x;
	float	dist_x;

	boundary_x = (float)d->map_x * TILE_SIZE;
	if (d->step_x > 0)
		boundary_x = (float)(d->map_x + 1) * TILE_SIZE;
	dist_x = boundary_x - d->px;
	if (d->step_x < 0)
		dist_x = d->px - ((float)d->map_x * TILE_SIZE);
	return (fabsf(dist_x / d->dir_x));
}

float	compute_first_boundary_y(t_dda *d)
{
	float	boundary_y;
	float	dist_y;

	boundary_y = (float)d->map_y * TILE_SIZE;
	if (d->step_y > 0)
		boundary_y = (float)(d->map_y + 1) * TILE_SIZE;
	dist_y = boundary_y - d->py;
	if (d->step_y < 0)
		dist_y = d->py - ((float)d->map_y * TILE_SIZE);
	return (fabsf(dist_y / d->dir_y));
}

int	compute_initial_sides(t_dda *d)
{
	d->side_x = compute_first_boundary_x(d);
	d->side_y = compute_first_boundary_y(d);
	return (0);
}
