/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_intercept.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:13:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 11:33:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

float	calculate_intercept(float player_pos, int flag)
{
	if (!flag)
		return (floorf(player_pos / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE - INNER_OFFSET);
	else
		return (floorf(player_pos / TILE_SIZE) * TILE_SIZE + INNER_OFFSET);
}
