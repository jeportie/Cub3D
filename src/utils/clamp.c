/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:16:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 22:32:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

/* 
 * @proto:  clamp(float value, float min, float max)
 * @brief:  clamps a value between a minimum and maximum range.
 *
 * @param:  value The value to clamp.
 * @param:  min The minimum allowable value.
 * @param:  max The maximum allowable value.
 * @return: float The clamped value.
 */

float	clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
