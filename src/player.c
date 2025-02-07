/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:26:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/07 14:55:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/player.h"
#include "../include/compute.h"

/*
 * player_init:
 * Finds 'P' in the g_map, sets player position to center of that tile,
 * faces left (-π/2). plane_x, plane_y are initialized to (0, 0.66) for
 * a ~60-degree FOV in plane mode.
 */

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
				data->player.plane_x = 0.0;
				data->player.plane_y = 0.66;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	rotate_player_angle(t_data *data, float rot_speed)
{
	data->player.angle += rot_speed;
	data->player.angle = normalize_angle(data->player.angle);
	get_direction_vector(data->player.angle, &data->player.dx, &data->player.dy);
}

int	player_update(t_data *data, double delta_time)
{
	float	move_distance;
	float	strafe_dx;
	float	strafe_dy;

	if (data->player.rot_left == true)
		rotate_player_angle(data, -ROT_SPEED * delta_time);
	if (data->player.rot_right == true)
		rotate_player_angle(data, ROT_SPEED * delta_time);
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
		get_perpendicular_vector(data->player.angle, &strafe_dx, &strafe_dy);
		data->player.x -= strafe_dx * move_distance;
		data->player.y -= strafe_dy * move_distance;
	}
	if (data->player.move_right)
	{
		get_perpendicular_vector(data->player.angle, &strafe_dx, &strafe_dy);
		data->player.x += strafe_dx * move_distance;
		data->player.y += strafe_dy * move_distance;
	}
	data->player.x = clamp(data->player.x, 0.0f, (float)WINDOW_WIDTH);
	data->player.y = clamp(data->player.y, 0.0f, (float)WINDOW_HEIGHT);
	return (0);
}
