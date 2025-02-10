/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_api.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:20:15 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 18:46:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/define.h"
#include "../../include/error.h"
#include "../../include/input.h"
#include "game.h"

const t_game_api	g_game_methods = {
	.init = init_game,
	.run = run_game,
	.destroy = destroy_game};

t_game	*create_game(void)
{
	t_game		*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->methods = &g_game_methods;
	return (game);
}

int	init_game(t_game *self)
{
	self->app = mlx_app_create(self->settings->window_width,
			self->settings->window_height, GAME_TITLE);
	if (!self->app)
	{
		free(self);
		return (1);
	}
	if (init_texture(self))
	{
		ft_dprintf(2, ERR_TEX_INIT);
		return (1);
	}
	player_init(self);
	print_map();
	if (clock_gettime(CLOCK_MONOTONIC, &self->graphics.last_time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (1);
	}
	return (0);
}

int	run_game(t_game *game)
{
	mlx_hook(game->app->win_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game->app->win_ptr, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game->app->mlx_ptr, game_loop, &game);
	ft_printf("Entering MLX event loop.\n");
	mlx_loop(game->app->mlx_ptr);
}

int			destroy_game(t_game *self)
{
	if (!self)
		return (-1);
	if (self->app)
	{
		if (self->app->win_ptr)
			mlx_destroy_window(self->app->mlx_ptr, self->app->win_ptr);
		free(self->app);
	}
	if (self->settings)
		free(self->settings);
	free(self);
}
