/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:11:50 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 22:31:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

/*
 * @proto: calculate_direction(float angle, double *dx, double *dy)
 * @brief: calculates the direction vector based on the given angle.
 * 
 * @param: angle The angle in radians.
 * @param: dx Pointer to store the calculated x-component.
 * @param: dy Pointer to store the calculated y-component.
 */

void	calculate_direction(float angle, double *dx, double *dy)
{
	*dx = cosf(angle);
	*dy = sinf(angle);
}

/* 
 * @proto:   calculate_strafe_direction(float angle, float *dx, float *dy)
 * @brief:   calculates the strafing direction vector based on the given angle.
 *           Strafing involves moving perpendicular to the current direction.
 * @param:   angle The current angle in radians.
 * @param:   dx Pointer to store the calculated x-component for strafing.
 * @param:   dy Pointer to store the calculated y-component for strafing.
 */
void	calculate_strafe_direction(float angle, float *dx, float *dy)
{
	*dx = cosf(angle + (M_PI / 2));
	*dy = sinf(angle + (M_PI / 2));
}
