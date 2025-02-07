/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_fisheye.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:16:48 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 23:03:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

/*
 * @proto:  correct_fisheye(float player_angle, float ray_angle, float distance)
 * @brief:  Corrects the distance of a ray to prevent fisheye distortion.
 *
 * @param:  player_angle The current angle of the player.
 * @param:  ray_angle The angle of the current ray.
 * @param:  distance The raw distance from the player to the wall.
 * @return: float The corrected distance.
 */

float	correct_fisheye(float player_angle, float ray_angle, float distance)
{
	float	angle_difference;

	angle_difference = player_angle - ray_angle;
	angle_difference = fmodf(angle_difference + M_PI, 2.0f * M_PI) - M_PI;
	return (distance * cosf(angle_difference));
}
