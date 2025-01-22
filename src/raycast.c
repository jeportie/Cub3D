/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:04:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/22 14:37:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/engine.h"
#include "../include/player.h"
#include "../include/colors.h"

int	draw_line(t_data *data, t_line_data ldata)
{
	t_line_vars	line;

	line.dx = ldata.x1 - ldata.x0;
	line.dy = ldata.y1 - ldata.y0;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	if (line.steps == 0)
	{
		put_pixel_to_image(&data->img, ldata.x0, ldata.y0, ldata.color);
		return (0);
	}
	line.inc_x = (float)line.dx / (float)line.steps;
	line.inc_y = (float)line.dy / (float)line.steps;
	line.cur_x = ldata.x0;
	line.cur_y = ldata.y0;
	line.i = 0;
	while (line.i <= line.steps)
	{
		put_pixel_to_image(&data->img, (int)line.cur_x,
			(int)line.cur_y, ldata.color);
		line.cur_x += line.inc_x;
		line.cur_y += line.inc_y;
		line.i++;
	}
	return (0);
}

t_rayinfo cast_vertical_ray(t_data *data, float ray_angle)
{
	t_ray_cast_vars	v;
	t_rayinfo		result;

	v.player_x = data->player.x;
	v.player_y = data->player.y;
	v.cos_a = cosf(ray_angle);
	v.sin_a = sinf(ray_angle);
	if (fabsf(v.cos_a) < EPSILON)
	{
		if (v.cos_a > 0)
			v.cos_a = EPSILON;
		else
			v.cos_a = -EPSILON;
	}
	v.flag = (v.cos_a < 0);
	if (data->use_inner_edge)
	{
		if (v.flag)
			v.intercept_primary = floorf(v.player_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE - INNER_OFFSET;
		else
			v.intercept_primary = floorf(v.player_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
	else
	{
		if (v.flag)
			v.intercept_primary = floorf(v.player_x / TILE_SIZE) * TILE_SIZE;
		else
			v.intercept_primary = floorf(v.player_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}	v.dist_primary = v.intercept_primary - v.player_x;
	v.tan_a = v.sin_a / v.cos_a;
	v.intercept_secondary = v.player_y + v.dist_primary * v.tan_a;
	if (v.flag)
		v.step_primary = -TILE_SIZE;
	else
		v.step_primary = TILE_SIZE;
	v.step_secondary = v.step_primary * v.tan_a;
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
	v.distance = sqrtf(v.delta_x * v.delta_x + v.delta_y * v.delta_y);
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
	h.sin_a = sinf(ray_angle);
	h.cos_a = cosf(ray_angle);
	if (fabsf(h.sin_a) < EPSILON)
	{
		if (h.sin_a > 0)
			h.sin_a = EPSILON;
		else
			h.sin_a = -EPSILON;
	}
	h.flag = (h.sin_a < 0);
	if (data->use_inner_edge)
	{
		if (h.flag)
			h.intercept_primary = floorf(h.player_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE - INNER_OFFSET;
		else
			h.intercept_primary = floorf(h.player_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
	else
	{
		if (h.flag)
			h.intercept_primary = floorf(h.player_y / TILE_SIZE) * TILE_SIZE;
		else
			h.intercept_primary = floorf(h.player_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
	h.dist_primary = h.intercept_primary - h.player_y;
	h.tan_a = h.cos_a / h.sin_a;
	h.intercept_secondary = h.player_x + h.dist_primary * h.tan_a;
	if (h.flag)
		h.step_primary = -TILE_SIZE;
	else
		h.step_primary = TILE_SIZE;
	h.step_secondary = h.step_primary * h.tan_a;
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
	h.distance = sqrtf(h.delta_x * h.delta_x + h.delta_y * h.delta_y);
	result.rx = h.ray_collision_x;
	result.ry = h.ray_collision_y;
	result.dist = h.distance;
	return (result);
}

int	draw_rays(t_data *data)
{
	int			i;
	const float	fov = FOV_DEGREES * (M_PI / 180.0f);
	float		start_angle;
	float		ray_angle;
	t_rayinfo	vertical_ray;
	t_rayinfo	horizontal_ray;
	t_rayinfo	chosen;
	t_line_data	ldata;

	start_angle = data->player.angle - (fov / 2);
	i = 0;
	while (i < RAYS)
	{
		ray_angle = start_angle + i * (fov / (RAYS - 1));
		while (ray_angle < 0)
			ray_angle += 2.0f * M_PI;
		while (ray_angle >= 2.0f * M_PI)
			ray_angle -= 2.0f * M_PI;
		vertical_ray = cast_vertical_ray(data, ray_angle);
		horizontal_ray = cast_horizontal_ray(data, ray_angle);
		if (vertical_ray.dist < horizontal_ray.dist)
			chosen = vertical_ray;
		else
			chosen = horizontal_ray;
		ldata.x0 = (int)data->player.x;
		ldata.y0 = (int)data->player.y;
		ldata.x1 = (int)chosen.rx;
		ldata.y1 = (int)chosen.ry;
		ldata.color = GREEN;
		draw_line(data, ldata);
		i++;
	}
	return (0);
}
