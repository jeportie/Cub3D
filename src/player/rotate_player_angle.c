/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player_angle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:31:39 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:56:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

int	rotate_player_angle(t_data *data, float rot_speed)
{
	t_coord	dir;

	data->player.pose.angle += rot_speed;
	data->player.pose.angle = normalize_angle(data->player.pose.angle);
	dir = get_direction_vector(data->player.pose.angle);
	data->player.pose.dx = dir.x;
	data->player.pose.dy = dir.y;
	return (0);
}
