/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:30:19 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:51:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/player.h"

int	player_pos(t_data *data, int row, int col)
{
	data->player.pose.x = col * TILE_SIZE + (TILE_SIZE / 2);
	data->player.pose.y = row * TILE_SIZE + (TILE_SIZE / 2);
	if (data->map[row * data->parse.map.width + col] == 'N')
		data->player.pose.angle = -M_PI / 2;
	if (data->map[row * data->parse.map.width + col] == 'S')
		data->player.pose.angle = M_PI / 2;
	if (data->map[row * data->parse.map.width + col] == 'E')
		data->player.pose.angle = M_PI;
	if (data->map[row * data->parse.map.width + col] == 'W')
		data->player.pose.angle = 0;
	data->player.pose.dx = cos(data->player.pose.angle);
	data->player.pose.dy = sin(data->player.pose.angle);
	return (0);
}

int	player_init(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->parse.map.height)
	{
		col = 0;
		while (col < data->parse.map.width)
		{
			if (data->map[row * data->parse.map.width + col] == 'N'
				|| data->map[row * data->parse.map.width + col] == 'S'
				|| data->map[row * data->parse.map.width + col] == 'E'
				|| data->map[row * data->parse.map.width + col] == 'W')
			{
				player_pos(data, row, col);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}
