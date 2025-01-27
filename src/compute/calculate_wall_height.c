/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:15:40 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 23:23:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

/*
 * @proto:  calculate_wall_height(float distance, float fov)
 * @brief:  calculates the height of the wall slice based on distance.
 *
 * @param:  corrected_distance The distance corrected for fisheye distortion.
 * @param:  fov The field of view in radians.
 * @return: int The calculated wall height, clamped to THREE_D_HEIGHT.
 */

int	calculate_wall_height(float distance, float fov)
{
	float	height;

	if (distance < 0.0001f)
		distance = 0.0001f;
	height = (TILE_SIZE / distance) * (THREE_D_WIDTH / 2) / tanf(fov / 2);
	if (height > THREE_D_HEIGHT)
		height = THREE_D_HEIGHT;
	return ((int)height);
}
