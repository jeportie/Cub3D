/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:12:36 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:20:45 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

/* 
 * @proto:  calculate_distance(float delta_x, float delta_y)
 * @brief:  calculate the distance with pytagore theorem.
 *
 * @param:  float the X coordinates of the point to mesure.
 * @param:  float the Y coordinates of the point to mesure.
 * @return: float the distance value.
 */

/*
float	calculate_distance(float delta_x, float delta_y)
{
	return (sqrtf(delta_x * delta_x + delta_y * delta_y));
}*/

float	calculate_distance(t_coord start, t_coord end)
{
	t_coord	delta;

	delta.x = fabs(start.x - end.x);
	delta.y = fabs(start.y - end.y);
	return (sqrtf(delta.x * delta.x + delta.y * delta.y));
}
