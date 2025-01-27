/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:26:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/25 23:27:33 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/player.h"
#include "../include/compute.h"

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
			if (g_map[row * MAP_WIDTH + col] == 'P')
			{
				data->player.x = col * TILE_SIZE + (TILE_SIZE / 2);
				data->player.y = row * TILE_SIZE + (TILE_SIZE / 2);
				data->player.angle = -M_PI / 2;
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
	float	rotation_factor;
	float	move_distance;
	float	strafe_dx;
	float	strafe_dy;

	rotation_factor = ROT_SPEED;
	if (data->player.rot_left)
		data->player.angle -= rotation_factor * (float)delta_time;
	if (data->player.rot_right)
		data->player.angle += rotation_factor * (float)delta_time;
	data->player.angle = normalize_angle(data->player.angle);
	calculate_direction(data->player.angle, &data->player.dx, &data->player.dy);
	move_distance = calculate_move_distance(SPEED, delta_time);
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
		calculate_strafe_direction(data->player.angle, &strafe_dx, &strafe_dy);
		data->player.x -= strafe_dx * move_distance;
		data->player.y -= strafe_dy * move_distance;
	}
	if (data->player.move_right)
	{
		calculate_strafe_direction(data->player.angle, &strafe_dx, &strafe_dy);
		data->player.x += strafe_dx * move_distance;
		data->player.y += strafe_dy * move_distance;
	}
	data->player.x = clamp(data->player.x, 0.0f, (float)WINDOW_WIDTH);
	data->player.y = clamp(data->player.y, 0.0f, (float)WINDOW_HEIGHT);
	return (0);
}
