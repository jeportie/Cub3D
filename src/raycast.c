/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:04:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 17:21:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/player.h"
#include "../include/compute.h"

int	intercept_mode(t_ray_cast_vars *ray, char c)
{
	if (c == 'v')
		ray->intercept_primary = calculate_intercept(ray->player_x, ray->flag, 'v');
	else if (c == 'h')
		ray->intercept_primary = calculate_intercept(ray->player_y, ray->flag, 'h');
	return (0);
}

t_rayinfo	cast_vertical_ray(t_data *data, float ray_angle)
{
	t_ray_cast_vars	v;
	t_rayinfo		result;

	v.player_x = data->player.x;
	v.player_y = data->player.y;
	v.cos_a = get_safe_cos(ray_angle);
	v.sin_a = get_safe_sin(ray_angle);
	v.flag = (v.cos_a < 0);
	intercept_mode(&v, 'v');
	v.dist_primary = v.intercept_primary - v.player_x;
	v.tan_a = calculate_tan_a(v.sin_a, v.cos_a);
	v.intercept_secondary = v.player_y + v.dist_primary * v.tan_a;
	v.step_primary = calculate_step_primary(v.flag, TILE_SIZE);
	v.step_secondary = calculate_step_secondary(v.step_primary, v.tan_a);
	v.ray_collision_x = v.intercept_primary;
	v.ray_collision_y = v.intercept_secondary;
	v.loop_counter = 0;
	while (v.loop_counter < MAP_WIDTH)
	{
		v.tile_x = (int)(v.ray_collision_x / TILE_SIZE);
		v.tile_y = (int)(v.ray_collision_y / TILE_SIZE);
		if (v.tile_x < 0 || v.tile_x >= MAP_WIDTH || v.tile_y < 0
			|| v.tile_y >= MAP_HEIGHT)
			break ;
		v.map_index = v.tile_y * MAP_WIDTH + v.tile_x;
		if (g_map[v.map_index] == '1')
			break ;
		v.ray_collision_x += v.step_primary;
		v.ray_collision_y += v.step_secondary;
		v.loop_counter++;
	}
	v.delta_x = v.ray_collision_x - v.player_x;
	v.delta_y = v.ray_collision_y - v.player_y;
	v.distance = calculate_distance(v.delta_x, v.delta_y);
	result.rx = v.ray_collision_x;
	result.ry = v.ray_collision_y;
	result.dist = v.distance;
	return (result);
}

t_rayinfo	cast_horizontal_ray(t_data *data, float ray_angle)
{
	t_ray_cast_vars	h;
	t_rayinfo		result;

	h.player_x = data->player.x;
	h.player_y = data->player.y;
	h.sin_a = get_safe_sin(ray_angle);
	h.cos_a = get_safe_cos(ray_angle);
	h.flag = (h.sin_a < 0);
	intercept_mode(&h, 'h');
	h.dist_primary = h.intercept_primary - h.player_y;
	h.tan_a = h.cos_a / h.sin_a;
	h.intercept_secondary = h.player_x + h.dist_primary * h.tan_a;
	h.step_primary = calculate_step_primary(h.flag, TILE_SIZE);
	h.step_secondary = calculate_step_secondary(h.step_primary, h.tan_a);
	h.ray_collision_x = h.intercept_secondary;
	h.ray_collision_y = h.intercept_primary;
	h.loop_counter = 0;
	while (h.loop_counter < MAP_HEIGHT)
	{
		h.tile_x = (int)(h.ray_collision_x / TILE_SIZE);
		h.tile_y = (int)(h.ray_collision_y / TILE_SIZE);
		if (h.tile_x < 0 || h.tile_x >= MAP_WIDTH || h.tile_y < 0
			|| h.tile_y >= MAP_HEIGHT)
			break ;
		h.map_index = h.tile_y * MAP_WIDTH + h.tile_x;
		if (g_map[h.map_index] == '1')
			break ;
		h.ray_collision_x += h.step_secondary;
		h.ray_collision_y += h.step_primary;
		h.loop_counter++;
	}
	h.delta_x = h.ray_collision_x - h.player_x;
	h.delta_y = h.ray_collision_y - h.player_y;
	h.distance = calculate_distance(h.delta_x, h.delta_y);
	result.rx = h.ray_collision_x;
	result.ry = h.ray_collision_y;
	result.dist = h.distance;
	return (result);
}
