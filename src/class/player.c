/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:33:57 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 20:12:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "player.h"
#include "map.h"
#include "../../include/compute.h"
#include "../engine/graphic_engine.h"
#include "../engine/texture_manager.h"

int	init_player(t_player *player)
{
	int	row;
	int	col;

	if (!player)
		return (1);
	ft_printf(DEB_PLAYER_INIT);
	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			if (g_map[row * MAP_WIDTH + col] == 'P')
			{
				player->transform.x = col * TILE_SIZE + (TILE_SIZE / 2);
				player->transform.y = row * TILE_SIZE + (TILE_SIZE / 2);
				player->transform.angle = -M_PI / 2;
				player->transform.dx = cos(player->transform.angle);
				player->transform.dy = sin(player->transform.angle);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

//put this into a more generic function player-entity
int	rotate_object(t_transform *transform, float rot_speed)
{
	transform->angle += rot_speed;
	transform->angle = normalize_angle(transform->angle);
	get_direction_vector(transform->angle, &transform->dx, &transform->dy);
	return (0);
}

int	update_player(t_player *player, double delta_time)
{
	t_transform	transform;
	float		move_distance;
	float		strafe_dx;
	float		strafe_dy;

	transform = player->transform;
	if (player->rot_left == true)
		rotate_object(&transform, -ROT_SPEED * delta_time);
	if (player->rot_right == true)
		rotate_object(&transform, ROT_SPEED * delta_time);
	move_distance = calculate_move_distance(SPEED, delta_time);
	if (player->move_up)
	{
		transform.x += transform.dx * move_distance;
		transform.y += transform.dy * move_distance;
	}
	if (player->move_down)
	{
		transform.x -= transform.dx * move_distance;
		transform.y -= transform.dy * move_distance;
	}
	if (player->move_left)
	{
		get_perpendicular_vector(transform.angle, &strafe_dx, &strafe_dy);
		transform.x -= strafe_dx * move_distance;
		transform.y -= strafe_dy * move_distance;
	}
	if (player->move_right)
	{
		get_perpendicular_vector(transform.angle, &strafe_dx, &strafe_dy);
		transform.x += strafe_dx * move_distance;
		transform.y += strafe_dy * move_distance;
	}
//	transform.x = clamp(transform.x, 0.0f, (float)WINDOW_WIDTH);
//	transform.y = clamp(transform.y, 0.0f, (float)WINDOW_HEIGHT);
	player->transform = transform;
	return (0);
}

int	render_player(t_player *player, t_game *game, int buffer_to_draw)
{
	t_graphics		*engine;

	engine = game->graphic_engine;
	buffer_to_draw = (engine->current_img + 1) % 2;
	draw_walls(game, &engine->buffer[buffer_to_draw]);
	if (game->settings->toogle_map)
	{
		draw_player(player, &engine->buffer[buffer_to_draw]);
		if (game->settings->toogle_rays)
			draw_rays(game, &engine->buffer[buffer_to_draw]);
	}
	return (0);
}

int	destroy_player(t_player *player)
{
	if (!player)
		return (-1);
	ft_printf(DEB_PLAYER_DESTROY);
	return (0);
}
