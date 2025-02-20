/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_tile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 13:39:24 by jeportie         ###   ########.fr       */
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

int	partial_init(t_coord s_c[2], t_partial_tile *pos, int *row, int *size)
{
	pos->start = s_c[0];
	pos->center = s_c[1];
	*size = MINIMAP_SCALE;
	*row = -1;
	return (0);
}

int	partial_helper(t_partial_tile *pos, int *row, int *col)
{
	pos->global.x = pos->start.x + (float)*col;
	pos->global.y = pos->start.y + (float)*row;
	pos->dist.x = pos->global.x - pos->center.x;
	pos->dist.y = pos->global.y - pos->center.y;
	return (0);
}

int	draw_partial_tile(t_coord s_c[2], int base_color, int radius, t_image *img)
{
	int				row;
	int				col;
	int				pixel_color;
	int				size;
	t_partial_tile	pos;

	partial_init(s_c, &pos, &row, &size);
	while (++row < size)
	{
		col = -1;
		while (++col < size)
		{
			partial_helper(&pos, &row, &col);
			if (pos.dist.x * pos.dist.x
				+ pos.dist.y * pos.dist.y <= radius * radius)
			{
				if (row == 0 || row == size - 1 || col == 0 || col == size - 1)
					pixel_color = GREY;
				else
					pixel_color = base_color;
				put_pixel_to_image(pos.global, pixel_color, img);
			}
		}
	}
	return (0);
}
