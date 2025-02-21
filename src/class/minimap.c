/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:17:39 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 10:31:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "../engine/graphic_engine.h"
#include "map.h" 
#include "player.h" 
#include "settings.h"

int	init_minimap(t_minimap *minimap)
{
	ft_printf(DEB_MINIMAP_INIT);
	minimap->scale = MINIMAP_SCALE;
	minimap->width = 200;
	minimap->height = 150;
	minimap->offset_x = THREE_D_X - 20;
	minimap->offset_y = 385;
	minimap->smooth_x = 0;
	minimap->smooth_y = 0;
	return (0);
}

int	loop_helper(t_minimap *minimap, t_minimap_coords *pos,
		t_coord start_center[2])
{
	pos->screen.x = pos->center.x
		+ ((pos->index.x - pos->frac.x) * minimap->scale);
	pos->screen.y = pos->center.y
		+ ((pos->index.y - pos->frac.y) * minimap->scale);
	pos->tl.x = pos->screen.x;
	pos->tl.y = pos->screen.y;
	pos->tr.x = pos->screen.x + minimap->scale;
	pos->tr.y = pos->screen.y;
	pos->bl.x = pos->screen.x;
	pos->bl.y = pos->screen.y + minimap->scale;
	pos->br.x = pos->screen.x + minimap->scale;
	pos->br.y = pos->screen.y + minimap->scale;
	pos->dist_tl = (pos->tl.x - pos->center.x) * (pos->tl.x - pos->center.x)
		+ (pos->tl.y - pos->center.y) * (pos->tl.y - pos->center.y);
	pos->dist_tr = (pos->tr.x - pos->center.x) * (pos->tr.x - pos->center.x)
		+ (pos->tr.y - pos->center.y) * (pos->tr.y - pos->center.y);
	pos->dist_bl = (pos->bl.x - pos->center.x) * (pos->bl.x - pos->center.x)
		+ (pos->bl.y - pos->center.y) * (pos->bl.y - pos->center.y);
	pos->dist_br = (pos->br.x - pos->center.x) * (pos->br.x - pos->center.x)
		+ (pos->br.x - pos->center.y) * (pos->br.y - pos->center.y);
	start_center[0] = pos->screen;
	start_center[1] = pos->center;
	return (0);
}

int	render_minimap_loop(t_minimap_coords pos, t_game *game,
		t_minimap *minimap, t_image *img)
{
	char	tiles;
	int		color;
	t_coord	start_center[2];
	float	radius_square;

	pos.index.y = -pos.range.y;
	while (pos.index.y <= pos.range.y)
	{
		pos.index.x = -pos.range.x;
		while (pos.index.x <= pos.range.x)
		{
			pos.tile.x = (int)pos.tile_center.x + pos.index.x;
			pos.tile.y = (int)pos.tile_center.y + pos.index.y;
			if (pos.tile.x < 0 || pos.tile.x >= MAP_WIDTH
				|| pos.tile.y < 0 || pos.tile.y >= MAP_HEIGHT)
			{
				pos.index.x++;
				continue ;
			}
			tiles = game->map->map[(int)pos.tile.y
				* MAP_WIDTH + (int)pos.tile.x];
			if (tiles == '1')
				color = WHITE;
			else
				color = BLACK;
			loop_helper(minimap, &pos, start_center);
			radius_square = pos.radius * pos.radius;
			if (!(pos.dist_tl <= radius_square && pos.dist_tr <= radius_square
					&& pos.dist_bl <= radius_square
					&& pos.dist_br <= radius_square))
				draw_partial_tile(start_center, color, pos.radius, img);
			else
				draw_minimap_tile(img, pos.screen, (int)minimap->scale, color);
			pos.index.x++;
		}
		pos.index.y++;
	}
	return (0);
}

int	init_pos_helper(t_minimap *minimap, t_minimap_coords *pos)
{
	pos->tile_center.x = floorf(minimap->smooth_x / TILE_SIZE);
	pos->tile_center.y = floorf(minimap->smooth_y / TILE_SIZE);
	pos->frac.x = (minimap->smooth_x / TILE_SIZE) - pos->tile_center.x;
	pos->frac.y = (minimap->smooth_y / TILE_SIZE) - pos->tile_center.y;
	pos->center.x = minimap->offset_x + (minimap->width / 2.0f);
	pos->center.y = minimap->offset_y + (minimap->height / 2.0f);
	pos->range.x = 8;
	pos->range.y = 6;
	return (0);
}

int	render_minimap(t_minimap *minimap, t_game *game, int buffer_to_draw)
{
	t_graphics			*gfx;
	t_image				*img;
	t_minimap_coords	pos;
	int					dot_size;

	pos.radius = 75.0f;
	if (!game->settings->toogle_minimap)
		return (0);
	gfx = game->graphic_engine;
	img = &gfx->buffer[buffer_to_draw];
	pos.player.x = game->player->transform.x;
	pos.player.y = game->player->transform.y;
	minimap->smooth_x -= (minimap->smooth_x - pos.player.x) * 0.2f;
	minimap->smooth_y -= (minimap->smooth_y - pos.player.y) * 0.2f;
	init_pos_helper(minimap, &pos);
	draw_filled_circle(pos.center, pos.radius, BLACK, img);
	render_minimap_loop(pos, game, minimap, img);
	dot_size = 4;
	pos.real_center.x = pos.center.x - dot_size / 2;
	pos.real_center.y = pos.center.y - dot_size / 2;
	draw_minimap_tile(img, pos.real_center, dot_size, RED);
	draw_direction_line(game->player->transform, pos.center, img);
	return (0);
}

int	destroy_minimap(t_minimap *minimap)
{
	ft_printf(DEB_MINIMAP_DSTROY);
	(void)minimap;
	return (0);
}
