/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:04:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/23 10:56:44 by jeportie         ###   ########.fr       */
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

int	intercept_mode(t_data *data, t_ray_cast_vars *ray, char c)
{
	float	player;

	if (c == 'v')
		player = ray->player_x;
	else if (c == 'h')
		player = ray->player_y;
	if (!data->use_inner_edge)
	{
		if (!ray->flag)
			ray->intercept_primary = floorf(player / TILE_SIZE) * TILE_SIZE + TILE_SIZE - INNER_OFFSET;
		else
			ray->intercept_primary = floorf(player / TILE_SIZE) * TILE_SIZE + INNER_OFFSET;
	}
	else
	{
		if (ray->flag)
			ray->intercept_primary = floorf(player / TILE_SIZE) * TILE_SIZE;
		else
			ray->intercept_primary = floorf(player / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
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
	intercept_mode(data, &v, 'v');
	v.dist_primary = v.intercept_primary - v.player_x;
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
	intercept_mode(data, &h, 'h');
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
		{
			ldata.color = GREEN;
			chosen = vertical_ray;
		}
		else
		{
			ldata.color = LIGHTGREEN;
			chosen = horizontal_ray;
		}
		ldata.x0 = (int)data->player.x;
		ldata.y0 = (int)data->player.y;
		ldata.x1 = (int)chosen.rx;
		ldata.y1 = (int)chosen.ry;
		draw_line(data, ldata);
		i++;
	}
	return (0);
}

void	draw_ceiling_floor(t_data *data)
{
	int x;
	int y;

	// Draw the ceiling
	for (x = THREE_D_X; x < WINDOW_WIDTH; x++)
	{
		for (y = 0; y < THREE_D_HEIGHT / 2; y++)
			put_pixel_to_image(&data->img, x, y, SKYBLUE);
	}

	// Draw the floor
	for (x = THREE_D_X; x < WINDOW_WIDTH; x++)
	{
		for (y = THREE_D_HEIGHT / 2; y < THREE_D_HEIGHT; y++)
			put_pixel_to_image(&data->img, x, y, DARKKHAKI);
	}
}

int	draw_3D_view(t_data *data)
{
    int			i;
    const float	fov = FOV_DEGREES * (M_PI / 180.0f);
    float		start_angle;
    float		ray_angle;
    t_rayinfo	vertical_ray;
    t_rayinfo	horizontal_ray;
    t_rayinfo	chosen;
    float		corrected_distance;
    int			wall_height;
	int			old_wall_height = 0;
    int			line_offset;
    int			x_screen;
	t_wall_type current_wall;
    t_wall_type	prev_wall = -1; // Initialize with an invalid value

    draw_ceiling_floor(data);
    start_angle = data->player.angle - (fov / 2);
    i = 0;
    while (i < RAYS)
    {
        ray_angle = start_angle + i * (fov / (RAYS - 1));

        // Normalize angle to [0, 2π)
        while (ray_angle < 0)
            ray_angle += 2.0f * M_PI;
        while (ray_angle >= 2.0f * M_PI)
            ray_angle -= 2.0f * M_PI;

        vertical_ray = cast_vertical_ray(data, ray_angle);
        horizontal_ray = cast_horizontal_ray(data, ray_angle);

        // Determine which ray hit first
        if (vertical_ray.dist < horizontal_ray.dist)
        {
            chosen = vertical_ray;
            chosen.color = RED;
			current_wall = WALL_VERTICAL;
        }
        else
        {
            chosen = horizontal_ray;
            chosen.color = GOLD; 
			current_wall = WALL_HORIZONTAL;
        }
        // Correct fish-eye distortion
        float ca = data->player.angle - ray_angle;
        // Normalize ca to [-π, π)
        if (ca < -M_PI)
            ca += 2.0f * M_PI;
        if (ca >= M_PI)
            ca -= 2.0f * M_PI;
        corrected_distance = chosen.dist * cosf(ca);

        // Prevent division by zero
        if (corrected_distance < 0.0001f)
            corrected_distance = 0.0001f;

        // Calculate wall height based on distance
        // Adjust scaling factor as needed
        wall_height = (int)((TILE_SIZE / corrected_distance) * (THREE_D_WIDTH / 2) / tanf(fov / 2));

        // Limit wall height to window height
        if (wall_height > THREE_D_HEIGHT)
            wall_height = THREE_D_HEIGHT;

        // Calculate vertical offset to center the wall slice
        line_offset = (THREE_D_HEIGHT / 2) - (wall_height / 2);

        // Calculate the x position on the screen for this ray
        x_screen = THREE_D_X + (i * THREE_D_WIDTH) / RAYS;

        // Draw the wall slice as a vertical line
        int	y;
        for (y = 0; y < wall_height; y++)
        {
            if (y == 0 || y == wall_height -1)
                put_pixel_to_image(&data->img, x_screen, y + line_offset, BLACK);
            else
			{
				if (current_wall != prev_wall || old_wall_height - wall_height > 20 || wall_height - old_wall_height > 20)
				{
					put_pixel_to_image(&data->img, x_screen, y + line_offset, BLACK);
				}
				else
					put_pixel_to_image(&data->img, x_screen, y + line_offset, chosen.color);
			}
        }
        prev_wall = current_wall;
		old_wall_height = wall_height;
        i++;
    }
    return (0);
}
