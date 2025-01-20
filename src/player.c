/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:26:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/20 23:01:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/player.h"

int	player_init(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			if (g_map[row][col] == 'P')
			{
				data->player.x = data->map_offset_x + col * TILE_SIZE
					+ (TILE_SIZE / 2);
				data->player.y = data->map_offset_y + row * TILE_SIZE
					+ (TILE_SIZE / 2);
				data->player.angle = 0.0;
				data->player.dx = cos(data->player.angle);
				data->player.dy = sin(data->player.angle);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	player_update(t_data *data, double delta_time)
{
	double	rotation_factor;
	double	move_distance;

	// 1) Rotation
	rotation_factor = ROT_SPEED * 5.0;
	if (data->player.rot_left)
		data->player.angle -= rotation_factor * delta_time;
	if (data->player.rot_right)
		data->player.angle += rotation_factor * delta_time;
	// Keep angle in [0, 2π)
	if (data->player.angle < 0)
		data->player.angle += 2.0 * M_PI;
	else if (data->player.angle >= 2.0 * M_PI)
		data->player.angle -= 2.0 * M_PI;
	// Recalculate dx, dy
	data->player.dx = cos(data->player.angle);
	data->player.dy = sin(data->player.angle);
	// 2) Translation
	move_distance = SPEED * delta_time;
	if (data->player.move_up)
	{
		data->player.x += data->player.dx * move_distance;
		data->player.y += data->player.dy * move_distance;
	}
	if (data->player.move_down)
	{
		data->player.x -= data->player.dx * move_distance;
		data->player.y -= data->player.dy * move_distance;
	}
	if (data->player.move_left)
	{
	    // Strafe left
		data->player.x += cos(data->player.angle - M_PI_2) * move_distance;
		data->player.y += sin(data->player.angle - M_PI_2) * move_distance;
	}
	if (data->player.move_right)
	{
	    // Strafe right
		data->player.x += cos(data->player.angle + M_PI_2) * move_distance;
		data->player.y += sin(data->player.angle + M_PI_2) * move_distance;
	}
	// 3) Basic boundary check
	if (data->player.x < 0)
		data->player.x = 0;
	if (data->player.y < 0)
		data->player.y = 0;
	if (data->player.x > WINDOW_WIDTH)
		data->player.x = WINDOW_WIDTH;
	if (data->player.y > WINDOW_HEIGHT)
		data->player.y = WINDOW_HEIGHT;
	return (0);
}
