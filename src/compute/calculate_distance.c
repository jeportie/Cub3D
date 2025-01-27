/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:12:36 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 23:13:04 by jeportie         ###   ########.fr       */
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

float	calculate_distance(float delta_x, float delta_y)
{
	return (sqrtf(delta_x * delta_x + delta_y * delta_y));
}
