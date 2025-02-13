/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:53:10 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 12:56:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "game_object.h"
#include "settings.h"
#include "player.h"
#include "map.h"
#include "../engine/callback_system.h"
#include "../engine/graphic_engine.h"
#include "../engine/core_engine.h"
#include "../../include/input.h"

const t_game_api	g_game_methods = {
	.init = init_game,
	.new_core = create_core_engine,
	.new_graphics = create_graphic_engine,
	.new_input = create_input_manager,	
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
	game->time_state = game->methods->new_core();
	game->graphic_engine = game->methods->new_graphics();
	game->input_manager = game->methods->new_input();
	game->player = game->methods->new_player();
	game->map = game->methods->new_map();

	game->object_count = 0;
	game_add_object(game, (t_game_object *)game->player);
	game_add_object(game, (t_game_object *)game->map);
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
	core_engine_init(self, self->time_state);
	input_manager_init(self, self->input_manager);
	graphic_engine_init(self, self->graphic_engine);
	return (0);
}

int	run_game(t_game *game)
{
	ft_printf("[Game Debug] run_game() called\n");
	mlx_hook(game->graphic_engine->app->win_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game->graphic_engine->app->win_ptr, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game->graphic_engine->app->mlx_ptr, game_loop, &game);
	ft_printf("[Game Debug] Entering MLX event loop.\n");
	mlx_loop(game->graphic_engine->app->mlx_ptr);
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
	if (self->graphic_engine->app)
	{
		if (self->graphic_engine->app->win_ptr)
			mlx_destroy_window(self->graphic_engine->app->mlx_ptr,
				self->graphic_engine->app->win_ptr);
		self->graphic_engine->app->win_ptr = NULL;
	}
	return (0);
}

static int	game_on_key_press(void *self, int keycode)
{
	t_game		*game;
	t_origin	*base;

	game = (t_game *)self;
	base = (t_origin *)self;
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC pressed. Exiting.\n");
		destroy_game(game);
		destroy_program(base);
		exit(0);
	}
	else if (keycode == KEY_F1)
		game->settings->toogle_rays = !game->settings->toogle_rays;
	else if (keycode == KEY_F2)
		game->settings->toogle_dda = !game->settings->toogle_dda;
	else if (keycode == KEY_F3)
		game->settings->toogle_texture = !game->settings->toogle_texture;
	else if (keycode == KEY_F4)
		game->settings->toogle_map = !game->settings->toogle_map;
	return (0);
}

const t_listener_api	g_game_listener_api = {
	.on_key_press = game_on_key_press,
};
