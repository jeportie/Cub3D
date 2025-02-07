/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:14:32 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/25 23:14:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

float	calculate_step_primary(int flag, float tile_size)
{
	if (flag)
		return (-tile_size);
	else
		return (tile_size);
}

float	calculate_step_secondary(float step_primary, float tan_a)
{
	return (step_primary * tan_a);
}
