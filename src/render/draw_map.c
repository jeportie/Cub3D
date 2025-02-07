/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:12:13 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/26 23:14:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/colors.h"
#include "../../include/render.h"

int	draw_map(t_image *img)
{
	int		row;
	int		col;
	char	tile;
	int		base_color;

	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			tile = g_map[row * MAP_WIDTH + col];
			if (tile == '1')
				base_color = WHITE;
			else
				base_color = BLACK;
			draw_tile(row, col, base_color, img);
			col++;
		}
		row++;
	}
	return (0);
}
