/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:02:17 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 18:01:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/player.h"
#include "../include/engine.h"
#include "../include/render.h"
#include "../include/error.h"

int	game_loop(t_data *data)
{
	struct timespec	current_time;
	double			delta;
	double			time_step;
	int				buffer_to_draw;

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
	time_step = 1.0 / 120.0;
	while (data->delta_accumulator >= time_step)
	{
		player_update(data, time_step);
		data->delta_accumulator -= time_step;
	}
	buffer_to_draw = (data->current_img + 1) % 2;
	clear_image(&data->img[buffer_to_draw], BLACK);
	draw_player_view(data, &data->img[buffer_to_draw]);
	if (!data->toogle_map)
	{
		draw_map(data, &data->img[buffer_to_draw]);
		draw_player(data, &data->img[buffer_to_draw]);
		if (data->toogle_rays)
			draw_rays(data, &data->img[buffer_to_draw]);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img[buffer_to_draw].img_ptr, 0, 0);
	data->current_img = buffer_to_draw;
	return (0);
}
