/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_api.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:20:15 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 21:37:44 by jeportie         ###   ########.fr       */
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

const t_game_api	g_game_methods = {
	.init = init_game,
	.run = run_game,
	.new_player = create_player,
	.new_map = create_map,
	.destroy = destroy_game};

t_game	*create_game(void)
{
	t_game		*game;

	game = gc_malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	ft_printf("[Game Debug] create_game() called\n");
	game->methods = &g_game_methods;
	game->player = game->methods->new_player();
	game->map = game->methods->new_map();
	return (game);
}

int	init_game(t_game *self)
{
	ft_printf("[Game Debug] init_game() called\n");
	if (!self->map)
		self->methods->new_map();
	self->map->methods->init(self->map);
	self->map->methods->print();
	self->player->methods->init(self->player);
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
	print_map();
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
	if (!self)
		return (-1);
	ft_printf("[Game Debug] destroy_game() called\n");
	if (self->player && self->player->methods->destroy)
		self->player->methods->destroy(self->player);
	if (self->map && self->map->methods->destroy)
		self->map->methods->destroy(self->map);
	if (self->app)
	{
		if (self->app->win_ptr)
			mlx_destroy_window(self->app->mlx_ptr, self->app->win_ptr);
		self->app->win_ptr = NULL;
	}
	return (0);
}
