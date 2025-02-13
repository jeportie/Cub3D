/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:33:57 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 22:47:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "player.h"
#include "map.h"
#include "../engine/core_engine.h"
#include "../../include/compute.h"

int	init_player(t_player *player)
{
	int	row;
	int	col;

	if (!player)
		return (1);
	ft_printf("[Player Debug] init_player() called\n");
	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			if (g_map[row * MAP_WIDTH + col] == 'P')
			{
				player->x = col * TILE_SIZE + (TILE_SIZE / 2);
				player->y = row * TILE_SIZE + (TILE_SIZE / 2);
				player->angle = -M_PI / 2;
				player->dx = cos(player->angle);
				player->dy = sin(player->angle);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

//put this into a more generic function player-entity
int	rotate_player_angle(t_player *player, float rot_speed)
{
	player->angle += rot_speed;
	player->angle = normalize_angle(player->angle);
	get_direction_vector(player->angle, &player->dx, &player->dy);
	return (0);
}

int	update_player(t_player *player, double delta_time)
{
	float	move_distance;
	float	strafe_dx;
	float	strafe_dy;

	if (player->rot_left == true)
		rotate_player_angle(player, -ROT_SPEED * delta_time);
	if (player->rot_right == true)
		rotate_player_angle(player, ROT_SPEED * delta_time);
	move_distance = calculate_move_distance(SPEED, delta_time);
	if (player->move_up)
	{
		player->x += player->dx * move_distance;
		player->y += player->dy * move_distance;
	}
	if (player->move_down)
	{
		player->x -= player->dx * move_distance;
		player->y -= player->dy * move_distance;
	}
	if (player->move_left)
	{
		get_perpendicular_vector(player->angle, &strafe_dx, &strafe_dy);
		player->x -= strafe_dx * move_distance;
		player->y -= strafe_dy * move_distance;
	}
	if (player->move_right)
	{
		get_perpendicular_vector(player->angle, &strafe_dx, &strafe_dy);
		player->x += strafe_dx * move_distance;
		player->y += strafe_dy * move_distance;
	}
	player->x = clamp(player->x, 0.0f, (float)WINDOW_WIDTH);
	player->y = clamp(player->y, 0.0f, (float)WINDOW_HEIGHT);
	return (0);
}

int	render_player(t_game *game)
{
	int				buffer_to_draw;
	t_graphics		*engine;

	engine = game->graphic_engine;
	buffer_to_draw = (engine->current_img + 1) % 2;
	draw_walls(game, &engine->buffer[buffer_to_draw]);
	if (game->settings->toogle_map)
	{
		draw_map(game->map, &engine->buffer[buffer_to_draw]);
		draw_player(game, &engine->buffer[buffer_to_draw]);
		if (game->settings->toogle_rays)
			draw_rays(game, &engine->buffer[buffer_to_draw]);
	}
	return (0);
}

int	destroy_player(t_player *player)
{
	if (!player)
		return (-1);
	ft_printf("[Player Debug] destroy_player() called\n");
	return (0);
}
