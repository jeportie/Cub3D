/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:04:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/05 21:32:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/compute.h"

t_rayinfo	cast_vertical_ray(t_data *data, float ray_angle)
{
	t_ray_cast	ray;

	ray.player_x = data->player.x;
	ray.player_y = data->player.y;
	ray.cos_a = get_safe_cos(ray_angle);
	ray.sin_a = get_safe_sin(ray_angle);
	ray.flag = (ray.cos_a < 0);
	ray.tan_a = calculate_tan_a(ray.sin_a, ray.cos_a);
	ray.intercept_x = calculate_intercept(ray.player_x, ray.flag);
	ray.intercept_y = ray.player_y + (ray.intercept_x - ray.player_x) * ray.tan_a;
	ray.step_x = calculate_step_primary(ray.flag, TILE_SIZE);
	ray.step_y = calculate_step_secondary(ray.step_x, ray.tan_a);
	while (true)
	{
		ray.result.tile_x = (int)(ray.intercept_x / TILE_SIZE);
		ray.result.tile_y = (int)(ray.intercept_y / TILE_SIZE);
		if (ray.result.tile_x < 0 || ray.result.tile_x >= MAP_WIDTH
			|| ray.result.tile_y < 0 || ray.result.tile_y >= MAP_HEIGHT
			|| g_map[ray.result.tile_y * MAP_WIDTH + ray.result.tile_x] == '1')
			break ;
		ray.intercept_x += ray.step_x;
		ray.intercept_y += ray.step_y;
	}
	ray.result.rx = ray.intercept_x;
	ray.result.ry = ray.intercept_y;
	ray.result.dist = calculate_distance(ray.result.rx - ray.player_x,
			ray.result.ry - ray.player_y);
	return (ray.result);
}

t_rayinfo	cast_horizontal_ray(t_data *data, float ray_angle)
{
	t_ray_cast	ray;

	ray.player_x = data->player.x;
	ray.player_y = data->player.y;
	ray.sin_a = get_safe_sin(ray_angle);
	ray.cos_a = get_safe_cos(ray_angle);
	ray.flag = (ray.sin_a < 0);
	ray.tan_a = ray.cos_a / ray.sin_a;
	ray.intercept_y = calculate_intercept(ray.player_y, ray.flag);
	ray.intercept_x = ray.player_x + (ray.intercept_y - ray.player_y) * ray.tan_a;
	ray.step_y = calculate_step_primary(ray.flag, TILE_SIZE);
	ray.step_x = calculate_step_secondary(ray.step_y, ray.tan_a);
	while (true)
	{
		ray.result.tile_x = (int)(ray.intercept_x / TILE_SIZE);
		ray.result.tile_y = (int)(ray.intercept_y / TILE_SIZE);
		if (ray.result.tile_x < 0 || ray.result.tile_x >= MAP_WIDTH
			|| ray.result.tile_y < 0 || ray.result.tile_y >= MAP_HEIGHT
			|| g_map[ray.result.tile_y * MAP_WIDTH + ray.result.tile_x] == '1')
			break ;
		ray.intercept_x += ray.step_x;
		ray.intercept_y += ray.step_y;
	}
	ray.result.rx = ray.intercept_x;
	ray.result.ry = ray.intercept_y;
	ray.result.dist = calculate_distance(ray.result.rx - ray.player_x,
			ray.result.ry - ray.player_y);
	return (ray.result);
}
