/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 09:39:53 by jeportie         ###   ########.fr       */
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
	while (py < MAP_TILE_SIZE)
	{
		px = 0;
		while (px < MAP_TILE_SIZE)
		{
			x = col * MAP_TILE_SIZE + px;
			y = row * MAP_TILE_SIZE + py;
			color = base_color;
			if (py == 0 || py == MAP_TILE_SIZE - 1
				|| px == 0 || px == MAP_TILE_SIZE - 1)
				color = GREY;
			put_pixel_to_image(img, x, y, color);
			px++;
		}
		py++;
	}
	return (0);
}
