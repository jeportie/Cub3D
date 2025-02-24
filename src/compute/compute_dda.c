/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:45:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 08:43:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raycast.h"

float	compute_first_boundary_x(t_dda *d)
{
	float	boundary_x;
	float	dist_x;

	boundary_x = (float)d->map.x * TILE_SIZE;
	if (d->step.x > 0)
		boundary_x = (float)(d->map.x + 1) * TILE_SIZE;
	dist_x = boundary_x - d->pos.x;
	if (d->step.x < 0)
		dist_x = d->pos.x - ((float)d->map.x * TILE_SIZE);
	return (fabsf(dist_x / d->dir.x));
}

float	compute_first_boundary_y(t_dda *d)
{
	float	boundary_y;
	float	dist_y;

	boundary_y = (float)d->map.y * TILE_SIZE;
	if (d->step.y > 0)
		boundary_y = (float)(d->map.y + 1) * TILE_SIZE;
	dist_y = boundary_y - d->pos.y;
	if (d->step.y < 0)
		dist_y = d->pos.y - ((float)d->map.y * TILE_SIZE);
	return (fabsf(dist_y / d->dir.y));
}

void	compute_initial_sides(t_dda *d, t_data *data)
{
	(void)data;
	d->side.x = compute_first_boundary_x(d);
	d->side.y = compute_first_boundary_y(d);
}
