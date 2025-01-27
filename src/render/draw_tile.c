/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 20:04:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"
#include "../../include/colors.h"
#include "../../include/render.h"

int	draw_tile(int row, int col, int base_color, t_image *img)
{
	int	py;
	int	px;
	int	x;
	int	y;
	int	color;

	py = 0;
	while (py < TILE_SIZE)
	{
		px = 0;
		while (px < TILE_SIZE)
		{
			x = col * TILE_SIZE + px;
			y = row * TILE_SIZE + py;
			color = base_color;
			if (py == 0 || py == TILE_SIZE - 1
				|| px == 0 || px == TILE_SIZE - 1)
				color = GREY;
			put_pixel_to_image(img, x, y, color);
			px++;
		}
		py++;
	}
	return (0);
}
