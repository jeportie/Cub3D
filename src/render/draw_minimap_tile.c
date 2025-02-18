/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_tile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 15:43:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

							
						
#include "../engine/graphic_engine.h"
#include "../../include/colors.h"

/**
 * draw_minimap_tile() - Draws a solid-colored square of `size × size` at
 *                       (x_start, y_start) in the image buffer.
 *
 * @param img:       The image buffer to draw into.
 * @param x_start:   Top-left X coordinate of where to draw the tile.
 * @param y_start:   Top-left Y coordinate of where to draw the tile.
 * @param size:      The size (width and height) of the tile in pixels.
 * @param base_color:The color to fill the tile with (e.g., WHITE or BLACK).
 *
 * If you want a border, you can do so by checking if (px == 0 || px == size-1 || ...).
 */

int	draw_minimap_tile(t_image *img, int x_start, int y_start, int size, int base_color)
{
	int	row;
	int	col;
	int	draw_x;
	int	draw_y;
	int	color;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			draw_x = x_start + col;
			draw_y = y_start + row;
			if (row == 0 || row == size - 1
				|| col == 0 || col == size - 1)
				color = GREY;
			else
				color = base_color;
			put_pixel_to_image(img, draw_x, draw_y, color);
			col++;
		}
		row++;
	}
	return (0);
}
