/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:06:17 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:48:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/settings.h"
#include "../engine/graphic_engine.h"
#include "../engine/texture_manager.h"
#include "../engine/raycaster.h"
#include "../../include/colors.h"

int	paint_wall(t_ray *ray, t_rndr_ctx *ctx, t_image *img, int is_same_tile)
{
	int		y;
	int		is_incomplete;
	t_coord	pos;

	y = 0;
	is_incomplete = 0;
	while (y < ray->wall_height)
	{
		pos.x = ray->x_screen;
		pos.y = y + ray->line_offset;
		if (y == 0 || y == ray->wall_height - 1)
			put_pixel_to_image(pos, BLACK, img);
		else if ((int)ray->current_wall != ctx->prev_wall || !is_same_tile)
		{
			if (ctx->old_wall_height > ray->wall_height)
			{
				is_incomplete = 1;
				put_pixel_to_image(pos, ray->chosen.color, img);
			}
			else
				put_pixel_to_image(pos, BLACK, img);
		}
		else
			put_pixel_to_image(pos, ray->chosen.color, img);
		y++;
	}
	return (is_incomplete);
}

int	draw_wall_slice(t_game *game, t_ray *ray, t_rndr_ctx *ctx, t_image *img)
{
	int	is_incomplete;
	int	is_same_tile;

	is_incomplete = 0;
	is_same_tile = 0;
	if (ray->chosen.tile_x == ctx->prev_tile_x
		&& ray->chosen.tile_y == ctx->prev_tile_y)
		is_same_tile = 1;
	if (game->settings->toogle_texture)
		texture_transform(&game->graphic_engine->texture, ray, img);
	else
		is_incomplete = paint_wall(ray, ctx, img, is_same_tile);
	ctx->prev_tile_x = ray->chosen.tile_x;
	ctx->prev_tile_y = ray->chosen.tile_y;
	ctx->prev_wall = ray->current_wall;
	ctx->old_wall_height = ray->wall_height;
	return (is_incomplete);
}
