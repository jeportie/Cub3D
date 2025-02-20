/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_tile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:37:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../../include/colors.h"

int	draw_minimap_tile(t_image *img, t_coord start, int size, int base_color)
{
	int		row;
	int		col;
	t_coord	draw;
	int		color;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			draw.x = start.x + col;
			draw.y = start.y + row;
			if (row == 0 || row == size - 1
				|| col == 0 || col == size - 1)
				color = GREY;
			else
				color = base_color;
			put_pixel_to_image(draw, color, img);
			col++;
		}
		row++;
	}
	return (0);
}
