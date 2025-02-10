/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine_api.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:57:23 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 21:57:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "../../include/player.h"
#include "../../include/error.h"

const t_core_engine_api	g_core_engine_methods = {
	.init = init_core_engine,
	.destroy = destroy_core_engine
};

double	get_time_in_seconds(struct timespec ts)
{
	return ((double)ts.tv_sec + (double)ts.tv_nsec / 1e9);
}

int	game_loop(t_game *self)
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
	delta = get_time_in_seconds(current_time) - get_time_in_seconds(self->last_time);
	self->last_time = current_time;
	if (delta > 0.1)
		delta = 0.1;
	self->delta_accumulator += delta;
	printf("delta = %.6f, accumulator = %.6f\n", delta, self->delta_accumulator);
	time_step = 1.0 / 120.0;
	while (self->delta_accumulator >= time_step)
	{
		player_update(self, time_step);
		self->delta_accumulator -= time_step;
	}
	buffer_to_draw = (self->current_img + 1) % 2;
	clear_image(&self->img[buffer_to_draw], BLACK);
	draw_player_view(self, &self->img[buffer_to_draw]);
	if (self->toogle_map)
	{
		draw_map(&self->img[buffer_to_draw]);
		draw_player(self, &self->img[buffer_to_draw]);
		if (self->toogle_rays)
			draw_rays(self, &self->img[buffer_to_draw]);
	}
	mlx_put_image_to_window(self->mlx, self->win, self->img[buffer_to_draw].img_ptr, 0, 0);
	self->current_img = buffer_to_draw;
	return (0);
}
