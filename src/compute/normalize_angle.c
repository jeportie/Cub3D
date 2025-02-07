/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:17:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 23:05:42 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

/* 
 * @proto:  normalize_angle(float angle)
 * @brief:  Normalizes an angle to the range [0, 2π).
 *
 * @param:  angle The angle in radians to normalize.
 * @return: float The normalized angle.
 */

float	normalize_angle(float angle)
{
	float	two_pi;

	two_pi = 2.0f * M_PI;
	angle = fmodf(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);
}
