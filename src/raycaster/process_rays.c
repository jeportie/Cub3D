/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:22:28 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:56:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/colors.h"
#include "../../include/compute.h"

int	process_ray(t_data *data, t_ray *ray, float start_angle, int i, float fov)
{
	ray->angle = normalize_angle(start_angle + (i * (fov / (RAYS - 1))));
	ray->chosen = cast_ray_dda(data, ray->angle);
	if (ray->chosen.map_index == 0)
	{
		ray->current_wall = WALL_VERTICAL;
		if (cosf(ray->angle) > 0.0f)
			ray->chosen.color = CADETBLUE;
		else
			ray->chosen.color = SILVER;
	}
	else
	{
		ray->current_wall = WALL_HORIZONTAL;
		if (sinf(ray->angle) > 0.0f)
			ray->chosen.color = DARKOLIVEGREEN;
		else
			ray->chosen.color = CORAL;
	}
	ray->corrected_distance = correct_fisheye(data->player.pose.angle,
			ray->angle, ray->chosen.dist);
	calculate_wall_height(ray);
	ray->line_offset = (THREE_D_HEIGHT / 2) - (ray->wall_height / 2);
	ray->x_screen = THREE_D_X + ((i * THREE_D_WIDTH) / RAYS);
	return (0);
}
