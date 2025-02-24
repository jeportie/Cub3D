/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:11:50 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:06:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

t_coord	get_direction_vector(float angle)
{
	t_coord	dir;

	dir.x = cosf(angle);
	dir.y = sinf(angle);
	return (dir);
}

t_coord	get_perpendicular_vector(float angle)
{
	t_coord	dir;

	dir.x = cosf(angle + (M_PI / 2));
	dir.y = sinf(angle + (M_PI / 2));
	return (dir);
}
