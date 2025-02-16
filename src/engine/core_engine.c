/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 13:38:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "graphic_engine.h"
#include "../class/game_object.h"
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
	int				buffer_to_draw;

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
	printf("delta = %.6f, accumulator = %.6f\n", delta, time_state->delta_accumulator);
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
	buffer_to_draw = (engine->current_img + 1) % 2;
	clear_image(&engine->buffer[buffer_to_draw], BLACK);

	for (int i = 0; i < game->object_count; i++)
	{
		t_game_object *obj = game->objects[i];
		if (obj && obj->active && obj->methods->render)
			obj->methods->render(obj, game);
	}
	mlx_put_image_to_window(engine->app->mlx_ptr, engine->app->win_ptr,
			engine->buffer[buffer_to_draw].img_ptr, 0, 0);
	engine->current_img = buffer_to_draw;
	return (0);
}

int core_engine_shutdown(t_game *game)
{
	(void)game;
    return (0);
}
