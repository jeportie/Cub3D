/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/17 20:08:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "graphic_engine.h"
#include "../class/game_object.h"
#include "../class/game.h"
#include "../../include/error.h"

t_core *create_core_engine(void)
{
	t_core	*core_engine;

	ft_printf(DEB_CORE_CREATE);
	core_engine = gc_malloc(sizeof(t_core));
	if (!core_engine)
		return (NULL);
	return (core_engine);
}

double	get_time_in_seconds(struct timespec ts)
{
	return ((double)ts.tv_sec + (double)ts.tv_nsec / 1e9);
}

int core_engine_init(t_core *time_state)
{
    if (clock_gettime(CLOCK_MONOTONIC, &time_state->last_time) != 0)
    {
        ft_dprintf(2, ERR_GETTIME);
        return (1);
    }
    time_state->delta_accumulator = 0.0;
	time_state->delta = 0;
	ft_printf(DEB_CORE_INIT);
    return (0);
}

int	game_loop(void *param)
{
	t_game			*game;
	t_core			*time_state;
	t_graphics		*engine;
	struct timespec	current_time;
	double			delta;
	double			time_step;

	game = (t_game *)param;
	time_state = game->time_state;
	engine = game->graphic_engine;

	if (clock_gettime(CLOCK_MONOTONIC, &current_time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (1);
	}
	delta = get_time_in_seconds(current_time)
		- get_time_in_seconds(time_state->last_time);
	time_state->last_time = current_time;
	if (delta > 0.1)
		delta = 0.1;
	time_state->delta_accumulator += delta;
	debug_log_add(&game->debug_log, "delta=%.6f, acc=%.6f",
		delta, time_state->delta_accumulator);
//	printf("delta = %.6f, accumulator = %.6f\n", delta, time_state->delta_accumulator);
	time_step = 1.0 / 120.0;
	while (time_state->delta_accumulator >= time_step)
	{
		for (int i = 0; i < game->object_count; i++)
		{
			t_game_object *obj = game->objects[i];
			if (obj && obj->active && obj->methods->update)
				obj->methods->update(obj, time_step);
		}
		time_state->delta_accumulator -= time_step;
	}
	time_state->delta = delta;
	time_state->fps_time_acc += delta;
	time_state->fps_frame_count += 1;
	if (time_state->fps_frame_count >= 60)
	{
		double avg_time_for_60 = time_state->fps_time_acc;
		double fps = 60.0 / avg_time_for_60;
		time_state->last_fps = fps;
		time_state->fps_time_acc = 0.0;
		time_state->fps_frame_count = 0;
	}
	return (graphic_engine_draw_frame(game, engine));
}

int core_engine_shutdown(t_game *game)
{
	(void)game;
    return (0);
}
