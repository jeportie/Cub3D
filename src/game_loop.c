/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:02:17 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 20:15:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minimap.h"
#include "../include/player.h"
#include "../include/engine.h"
#include "../include/raycast.h"
#include "../include/error.h"

int	game_loop(t_data *data)
{
	struct timespec	current_time;
	double			delta;
	double			time_step;

	if (clock_gettime(CLOCK_MONOTONIC, &current_time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (1);
	}
	delta = get_time_in_seconds(current_time) - get_time_in_seconds(data->last_time);
	data->last_time = current_time;
	if (delta > 0.1)
		delta = 0.1;
	data->delta_accumulator += delta;
	printf("delta = %.6f, accumulator = %.6f\n", delta, data->delta_accumulator);
	time_step = 1.0 / 60.0;
	while (data->delta_accumulator >= time_step)
	{
		player_update(data, time_step);
		data->delta_accumulator -= time_step;
	}
	clear_image(&data->img, 0x000000);
	draw_map(data);
	draw_player(data);
	draw_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
