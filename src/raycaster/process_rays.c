/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:22:28 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 11:44:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/colors.h"
#include "../../include/compute.h"

int	process_vertical(t_ray *ray)
{
	ray->current_wall = WALL_VERTICAL;
	if (cosf(ray->angle) > 0.0f)
		ray->chosen.color = CADETBLUE;
	else
		ray->chosen.color = SILVER;
	return (0);
}

int	process_horizontal(t_ray *ray)
{
	ray->current_wall = WALL_HORIZONTAL;
	if (sinf(ray->angle) > 0.0f)
		ray->chosen.color = DARKOLIVEGREEN;
	else
		ray->chosen.color = CORAL;
	return (0);
}

int	process_ray(t_data *data, t_ray *ray, float start_angle, int i)
{
	double	fov;

	fov = FOV_DEGREES * (M_PI / 180.0f);
	ray->angle = normalize_angle(start_angle + (i * (fov / (RAYS - 1))));
	ray->chosen = cast_ray_dda(data, ray->angle);
	if (ray->chosen.map_index == 0)
		process_vertical(ray);
	else
		process_horizontal(ray);
	ray->corrected_distance = correct_fisheye(data->player.pose.angle,
			ray->angle, ray->chosen.dist);
	calculate_wall_height(ray);
	ray->line_offset = (THREE_D_HEIGHT / 2) - (ray->wall_height / 2);
	ray->x_screen = THREE_D_X + ((i * THREE_D_WIDTH) / RAYS);
	return (0);
}
