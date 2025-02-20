/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:42:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../../include/colors.h"

int	draw_tile(int row, int col, int base_color, t_image *img)
{
	t_coord	index;
	t_coord	pos;
	int		color;

	index.y = 0;
	while (index.y < TILE_SIZE)
	{
		index.x = 0;
		while (index.x < TILE_SIZE)
		{
			pos.x = col * TILE_SIZE + index.x;
			pos.y = row * TILE_SIZE + index.y;
			color = base_color;
			if (index.y == 0 || index.y == TILE_SIZE - 1
				|| index.x == 0 || index.x == TILE_SIZE - 1)
				color = GREY;
			put_pixel_to_image(pos, color, img);
			index.x++;
		}
		index.y++;
	}
	return (0);
}
