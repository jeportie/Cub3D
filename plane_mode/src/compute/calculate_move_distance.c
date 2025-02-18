/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move_distance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:13:56 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 22:54:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

/*
 * @proto:  calculate_move_distance(float speed, double delta_time) 
 * @brief:  calculates the movement distance based on speed and delta_time.
 *  
 * @param:  speed The movement speed.
 * @param:  delta_time The elapsed time since the last update.
 * @return: float The calculated movement distance.
 */

float	calculate_move_distance(float speed, double delta_time)
{
	return (speed * (float)delta_time);
}
