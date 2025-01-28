/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:46:37 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/28 16:26:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/modes.h"
#include "../../include/engine.h"
#include "../../include/error.h"
#include "../../include/compute.h"
#include "../../include/define.h"
#include "../../include/cub3d.h"

/*
** This function destroys old images if needed, zeroes out data structures,
** then calls either angle_init_game or plane_init_game to set up everything.
*/

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

/*
** Example angle-based init (pixel coords for player).
** You can put more logic here or keep using your existing player_init().
** The difference is that we might place the player in typical pixel coords.
*/

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
	find_and_init_player_pixel(data); /* sets player.x/y from 'P' tile */

	data->player.angle = -M_PI / 2;
	calculate_direction((float)data->player.angle,
		&data->player.dx, &data->player.dy);

	data->use_dda = false; /* or whatever default you want */
	ft_printf("Initialized ANGLE (pixel-based) mode.\n");
	return (0);
}


/*
** Example tile-based init (plane coords).
** This is the "Lode" approach, 1 tile = 1.0 unit in your math.
*/

int	plane_init_game(t_data *data)
{
	ft_bzero(&data->player, sizeof(t_player));
	/* place the player in tile units (like Lode at e.g. 22.0, 12.0) */
	data->player.x = 22.0;  /* tile-based position, not pixels! */
	data->player.y = 12.0;
	data->player.angle = M_PI; /* facing left, for example */
	calculate_direction((float)data->player.angle,
		&data->player.dx, &data->player.dy);
	data->player.plane_x = 0.0;
	data->player.plane_y = 0.66;
	data->use_dda = true; /* or whichever default you want for plane mode */
	ft_printf("Initialized PLANE (tile-based) mode.\n");
	return (0);
}
