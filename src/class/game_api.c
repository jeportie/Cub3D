/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_api.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:20:15 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 18:40:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "game.h"
#include "settings.h"
#include "mlx_manager.h"
#include "graphic_engine.h"
#include "input_manager.h"
#include "player.h"
#include "map.h"
#include "texture_manager.h"
#include "game_object.h"

const t_game_api	g_game_methods = {
	.init = init_game,
	.run = run_game,
	.new_player = create_player,
	.new_map = create_map,
	.destroy = destroy_game};

int	game_add_object(t_game *game, t_game_object *obj)
{
	if (!obj)
		return (1);
	if (game->object_count >= MAX_OBJECTS)
	{
		ft_dprintf(2, "[Game] object array is full!\n");
		return (1);
	}
	game->objects[game->object_count++] = obj;
	return (0);
}

t_game	*create_game(void)
{
	t_game		*game;

	game = gc_malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	ft_printf("[Game Debug] create_game() called\n");
	game->methods = &g_game_methods;

	game->object_count = 0;
	game->player = game->methods->new_player();
	game->map = game->methods->new_map();

	/* Add them to our objects array, so we can do unified update calls. */
	/* (Cast them to (t_game_object*) because they embed that base struct) */
	game_add_object(game, (t_game_object*)game->player);
	game_add_object(game, (t_game_object*)game->map);
	return (game);
}

int	init_game(t_game *self)
{
	int				i;
	t_game_object	*object;

	ft_printf("[Game Debug] init_game() called\n");
	i = 0;
	while (i < self->object_count)
	{
		object = self->objects[i];
		if (object && object->methods && object->methods->init)
			object->methods->init(object);
		if (object && object->methods && object->methods->print)
			object->methods->print();
		i++;
	}
	self->app = mlx_app_create(self->settings->window_width,
			self->settings->window_height, GAME_TITLE);
	if (!self->app)
	{
		ft_dprintf(2, "[Game Error] Failed to init MLX.\n");
		return (1);
	}
	if (init_texture(self))
	{
		ft_dprintf(2, ERR_TEX_INIT);
		return (1);
	}
	if (clock_gettime(CLOCK_MONOTONIC, &self->graphics->last_time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (1);
	}
	self->graphics->delta_accumulator = 0.0;
	self->graphics->current_img = 0;
	return (0);
}

int	run_game(t_game *game)
{
	ft_printf("[Game Debug] run_game() called\n");
	mlx_hook(game->app->win_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game->app->win_ptr, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game->app->mlx_ptr, game_loop, &game);
	ft_printf("[Game Debug] Entering MLX event loop.\n");
	mlx_loop(game->app->mlx_ptr);
	return (0);
}

int	destroy_game(t_game *self)
{
	int				i;
	t_game_object	*object;

	if (!self)
		return (-1);
	ft_printf("[Game Debug] destroy_game() called\n");
	i = 0;
	while (i < self->object_count)
	{
		object = self->objects[i];
		if (object && object->methods && object->methods->destroy)
			object->methods->destroy(object);
		i++;
	}
	self->object_count = 0;
	if (self->app)
	{
		if (self->app->win_ptr)
			mlx_destroy_window(self->app->mlx_ptr, self->app->win_ptr);
		self->app->win_ptr = NULL;
	}
	return (0);
}
