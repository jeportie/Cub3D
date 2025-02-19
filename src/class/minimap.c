/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:17:39 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/19 19:20:45 by jeportie         ###   ########.fr       */
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

int	draw_minimap_partial_tile(t_image *img, int x_start, int y_start, int size,
		int base_color, int center_x, int center_y, int radius)
{
	int	row;
	int	col;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			int global_x = x_start + col;
			int global_y = y_start + row;
			int dx = global_x - center_x;
			int dy = global_y - center_y;
			// Only draw if the pixel is inside the circle
			if (dx * dx + dy * dy <= radius * radius)
			{
			    int pixel_color;
			    if (row == 0 || row == size - 1 || col == 0 || col == size - 1)
			        pixel_color = GREY;
			    else
			        pixel_color = base_color;
			    put_pixel_to_image(img, global_x, global_y, pixel_color);
			}
		}
	}
	return 0;
}

int	render_minimap(t_minimap *minimap, t_game *game, int buffer_to_draw)
{
	t_graphics	*gfx;
	t_image		*img;
	float		px;
	float		py;
	float		center_x;
	float		center_y;
	int			range_x;
	int			range_y;
	int			dx;
	int			dy;
	int			dot_size;
	float		tile_center_x;
	float		tile_center_y;
	float		frac_x;
	float		frac_y;
	float		radius;
	t_coord		center;
	t_coord		real_center;

	radius = 75.0f;
	if (!game->settings->toogle_minimap)
		return (0);
	gfx = game->graphic_engine;
	img = &gfx->buffer[buffer_to_draw];
	px = game->player->transform.x;
	py = game->player->transform.y;
	minimap->smooth_x -= (minimap->smooth_x - px) * 0.2f;
	minimap->smooth_y -= (minimap->smooth_y - py) * 0.2f;
	tile_center_x = floorf(minimap->smooth_x / TILE_SIZE);
	tile_center_y = floorf(minimap->smooth_y / TILE_SIZE);
	frac_x = (minimap->smooth_x / TILE_SIZE) - tile_center_x;
	frac_y = (minimap->smooth_y / TILE_SIZE) - tile_center_y;
	center_x = minimap->offset_x + (minimap->width / 2.0f);
	center_y = minimap->offset_y + (minimap->height / 2.0f);
	range_x = 8;
	range_y = 6;
	center.x = center_x;
	center.y = center_y;
	draw_filled_circle(center, radius, BLACK, img);
	dy = -range_y;
	while (dy <= range_y)
	{
		dx = -range_x;
		while (dx <= range_x)
		{
			int		tile_x;
			int		tile_y;
			char	tile;
			int		color;
			float	screen_x;
			float	screen_y;

			tile_x = (int)tile_center_x + dx;
			tile_y = (int)tile_center_y + dy;
			if (tile_x < 0 || tile_x >= MAP_WIDTH
				|| tile_y < 0 || tile_y >= MAP_HEIGHT)
			{
				dx++;
				continue ;
			}
			tile = game->map->map[tile_y * MAP_WIDTH + tile_x];
			color = (tile == '1') ? WHITE : BLACK;
			screen_x = center_x + ((dx - frac_x) * minimap->scale);
			screen_y = center_y + ((dy - frac_y) * minimap->scale);

			float tl_x = screen_x;
			float tl_y = screen_y;
			float tr_x = screen_x + minimap->scale;
			float tr_y = screen_y;
			float bl_x = screen_x;
			float bl_y = screen_y + minimap->scale;
			float br_x = screen_x + minimap->scale;
			float br_y = screen_y + minimap->scale; 
			float rad_sq = radius * radius;
			float d_tl = (tl_x - center_x) * (tl_x - center_x) + (tl_y - center_y) * (tl_y - center_y);
			float d_tr = (tr_x - center_x) * (tr_x - center_x) + (tr_y - center_y) * (tr_y - center_y);
			float d_bl = (bl_x - center_x) * (bl_x - center_x) + (bl_y - center_y) * (bl_y - center_y);
			float d_br = (br_x - center_x) * (br_x - center_x) + (br_y - center_y) * (br_y - center_y);
			t_coord	screen;
        
			screen.x = screen_x;
			screen.y = screen_y;
			if (!(d_tl <= rad_sq && d_tr <= rad_sq && d_bl <= rad_sq && d_br <= rad_sq))
			{
				draw_minimap_partial_tile(img, (int)screen_x, (int)screen_y,
						(int)minimap->scale, color, (int)center_x, (int)center_y, radius);
			}
			else
				draw_minimap_tile(img, screen, (int)minimap->scale, color);
			dx++;
		}
		dy++;
	}
	dot_size = 4;
	real_center.x = center_x - dot_size / 2;
	real_center.y = center_y - dot_size / 2;
	draw_minimap_tile(img, real_center, dot_size, RED);
	draw_direction_line(game->player->transform, center, img);
	return (0);
}

int	destroy_minimap(t_minimap *minimap)
{
	ft_printf(DEB_MINIMAP_DSTROY);
	(void)minimap;
	return (0);
}
