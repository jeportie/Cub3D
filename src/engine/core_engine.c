/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/12 23:30:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "graphic_engine.h"
#include "../class/game_object.h"
#include "../../include/error.h"

double	get_time_in_seconds(struct timespec ts)
{
	return ((double)ts.tv_sec + (double)ts.tv_nsec / 1e9);
}

int core_engine_init(t_game *game, t_graphics *engine)
{
    if (clock_gettime(CLOCK_MONOTONIC, &game->graphic_engine->last_time) != 0)
    {
        ft_dprintf(2, ERR_GETTIME);
        return (1);
    }
    game->graphic_engine->delta_accumulator = 0.0;
    return (0);
}

int core_engine_run(t_game *game, t_graphics *engine)
{
    mlx_loop_hook(engine->app->mlx_ptr, &game_loop, game);
    mlx_loop(engine->app->mlx_ptr);
    return (0);
}

int	game_loop(t_game *game)
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
	delta = get_time_in_seconds(current_time) - get_time_in_seconds(game->last_time);
	game->last_time = current_time;
	if (delta > 0.1)
		delta = 0.1;
	game->delta_accumulator += delta;
	printf("delta = %.6f, accumulator = %.6f\n", delta, game->delta_accumulator);
	time_step = 1.0 / 120.0;
	while (game->delta_accumulator >= time_step)
	{
		for (int i = 0; i < game->object_count; i++)
		{
			t_game_object *obj = game->objects[i];
			if (obj && obj->active && obj->methods->update)
				obj->methods->update(obj, time_step);
		}
		game->delta_accumulator -= time_step;
	}
	buffer_to_draw = (game->current_img + 1) % 2;
	clear_image(&game->img[buffer_to_draw], BLACK);

	for (int i = 0; i < game->object_count; i++)
	{
		t_game_object *obj = game->objects[i];
		if (obj && obj->active && obj->vtable->render)
			obj->vtable->render(obj, &game->graphics->buffer[buffer_to_draw]);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img[buffer_to_draw].img_ptr, 0, 0);
	game->current_img = buffer_to_draw;
	return (0);
}

int core_engine_shutdown(t_game *game)
{
    return (0);
}
/* 
