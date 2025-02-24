/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:31:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 08:13:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/player.h"
#include "../../include/compute.h"

static int	player_rotate(t_data *data, double delta_time)
{
	if (data->player.rot_left == true)
		rotate_player_angle(data, -ROT_SPEED * delta_time);
	if (data->player.rot_right == true)
		rotate_player_angle(data, ROT_SPEED * delta_time);
	return (0);
}

static int	player_move_ud(t_data *data, float move_distance)
{
	if (data->player.move_up)
	{
		data->player.pose.x += data->player.pose.dx * move_distance;
		data->player.pose.y += data->player.pose.dy * move_distance;
	}
	if (data->player.move_down)
	{
		data->player.pose.x -= data->player.pose.dx * move_distance;
		data->player.pose.y -= data->player.pose.dy * move_distance;
	}
	return (0);
}

static int	player_move_lr(t_data *data, float move_distance)
{
	t_coord	strafe_dir;

	if (data->player.move_left)
	{
		strafe_dir = get_perpendicular_vector(data->player.pose.angle);
		data->player.pose.x -= strafe_dir.x * move_distance;
		data->player.pose.y -= strafe_dir.y * move_distance;
	}
	if (data->player.move_right)
	{
		strafe_dir = get_perpendicular_vector(data->player.pose.angle);
		data->player.pose.x += strafe_dir.x * move_distance;
		data->player.pose.y += strafe_dir.y * move_distance;
	}
	return (0);
}

int	player_update(t_data *data, double delta_time)
{
	float	move_distance;

	player_rotate(data, delta_time);
	move_distance = calculate_move_distance(SPEED, delta_time);
	player_move_ud(data, move_distance);
	player_move_lr(data, move_distance);
	return (0);
}
