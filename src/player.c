/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:26:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/30 16:18:24 by jeportie         ###   ########.fr       */
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
	calculate_direction(data->player.angle, &data->player.dx, &data->player.dy);
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

static double plane_move_speed = 4.0; // tiles per second
static double plane_rot_speed  = 2.0; // radians per second

int	player_plane_update(t_data *data, double delta_time)
{
	double moveSpeed;
	double rotSpeed;
	double old_dx;
	double old_plane;

	moveSpeed = plane_move_speed * delta_time;
	rotSpeed  = plane_rot_speed  * delta_time;

	if (data->player.move_up)
	{
		data->player.x += data->player.dx * moveSpeed;
		data->player.y += data->player.dy * moveSpeed;
	}
	if (data->player.move_down)
	{
		data->player.x -= data->player.dx * moveSpeed;
		data->player.y -= data->player.dy * moveSpeed;
	}
	if (data->player.move_left)
	{
		data->player.x -= data->player.plane_x * moveSpeed;
		data->player.y -= data->player.plane_y * moveSpeed;
	}
	if (data->player.move_right)
	{
		data->player.x += data->player.plane_x * moveSpeed;
		data->player.y += data->player.plane_y * moveSpeed;
	}
	if (data->player.rot_left)
	{
		old_dx = data->player.dx;
		old_plane = data->player.plane_x;
		data->player.dx = data->player.dx * cos(rotSpeed)
			- data->player.dy * sin(rotSpeed);
		data->player.dy = old_dx * sin(rotSpeed)
			+ data->player.dy * cos(rotSpeed);
		data->player.plane_x = data->player.plane_x * cos(rotSpeed)
			- data->player.plane_y * sin(rotSpeed);
		data->player.plane_y = old_plane * sin(rotSpeed)
			+ data->player.plane_y * cos(rotSpeed);
	}
	if (data->player.rot_right)
	{
		old_dx = data->player.dx;
		old_plane = data->player.plane_x;
		data->player.dx = data->player.dx * cos(-rotSpeed)
			- data->player.dy * sin(-rotSpeed);
		data->player.dy = old_dx * sin(-rotSpeed)
			+ data->player.dy * cos(-rotSpeed);
		data->player.plane_x = data->player.plane_x * cos(-rotSpeed)
			- data->player.plane_y * sin(-rotSpeed);
		data->player.plane_y = old_plane * sin(-rotSpeed)
			+ data->player.plane_y * cos(-rotSpeed);
	}
	// (Optional) If you want collisions, you can clamp x,y or check g_map[] here
	// e.g. if (g_map[(int)player.y * MAP_WIDTH + (int)player.x] == '1') then revert
	return (0);
}
