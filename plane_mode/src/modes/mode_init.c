/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:46:37 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/31 12:57:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/modes.h"
#include "../../include/engine.h"
#include "../../include/error.h"
#include "../../include/compute.h"
#include "../../include/define.h"
#include "../../include/cub3d.h"

int	re_init_game(t_data *data, bool plane_mode)
{
	if (data->img[0].img_ptr)
		mlx_destroy_image(data->mlx, data->img[0].img_ptr);
	if (data->img[1].img_ptr)
		mlx_destroy_image(data->mlx, data->img[1].img_ptr);
	ft_memset(data->img, 0, sizeof(data->img));
	data->current_img = 0;
	data->use_plane_mode = plane_mode;
	if (init_image(data) != 0)
	{
		ft_dprintf(2, ERR_MLX_IMAGE);
		return (0);
	}
	if (clock_gettime(CLOCK_MONOTONIC, &data->last_time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (0);
	}
	if (plane_mode == true)
		plane_init_game(data);
	else
		angle_init_game(data);
	ft_printf("Re-initialized game. plane_mode = %d\n", plane_mode);
	return (0);
}

int	find_and_init_player_pixel(t_data *data)
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
				data->player.x = (col + 0.5) * TILE_SIZE;
				data->player.y = (row + 0.5) * TILE_SIZE;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	angle_init_game(t_data *data)
{
	ft_bzero(&data->player, sizeof(t_player));
	find_and_init_player_pixel(data);
	data->player.angle = -M_PI;
	calculate_direction((float)data->player.angle,
		&data->player.dx, &data->player.dy);
	data->use_dda = false;
	ft_printf("Initialized ANGLE (pixel-based) mode.\n");
	return (0);
}

int	find_and_init_player_plane(t_data *data)
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
				data->player.x = col + 0.5;
				data->player.y = row + 0.5;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	plane_init_game(t_data *data)
{
	ft_bzero(&data->player, sizeof(t_player));
	find_and_init_player_plane(data);
	data->player.angle = M_PI;
	calculate_direction((float)data->player.angle,
		&data->player.dx, &data->player.dy);
	data->player.plane_x = 0.0;
	data->player.plane_y = 0.88;
	data->use_dda = true;
	ft_printf("Initialized PLANE (tile-based) mode.\n");
	return (0);
}
