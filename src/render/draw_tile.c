/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/23 21:34:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"
#include "../../include/colors.h"
#include "../../include/render.h"

int	draw_tile(int row, int col, int base_color, t_image *img)
{
	t_coord	pixel;
	t_coord	pos;
	int		color;

	pixel.y = 0;
	while (pixel.y < TILE_SIZE)
	{
		pixel.x = 0;
		while (pixel.x < TILE_SIZE)
		{
			pos.x = col * TILE_SIZE + pixel.x;
			pos.y = row * TILE_SIZE + pixel.y;
			color = base_color;
			if (pixel.y == 0 || pixel.y == TILE_SIZE - 1
				|| pixel.x == 0 || pixel.x == TILE_SIZE - 1)
				color = GREY;
			put_pixel_to_image(pos, color, img);
			pixel.x++;
		}
		pixel.y++;
	}
	return (0);
}
