/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:15:40 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/07 13:48:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

int	calculate_wall_height(t_ray *ray)
{
	float	height;
	float	distance;
	float	fov;

	distance = ray->corrected_distance;
	fov = FOV_DEGREES * (M_PI / 180.0f);
	if (distance < 0.0001f)
		distance = 0.0001f;
	height = (TILE_SIZE / distance) * (THREE_D_WIDTH / 2) / tanf(fov / 2);
	ray->true_wall_height = height;
	if (height > THREE_D_HEIGHT)
		height = THREE_D_HEIGHT;
	ray->wall_height = height;
	return (0);
}
