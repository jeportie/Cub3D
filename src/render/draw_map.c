/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:12:13 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 17:20:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/colors.h"
#include "../../include/render.h"

int	draw_map(t_data *data, t_image *img)
{
	int		row;
	int		col;
	char	tile;
	int		base_color;

	row = 0;
	while (row < data->parse.map.height)
	{
		col = 0;
		while (col < data->parse.map.width)
		{
			tile = data->map[row * data->parse.map.width + col];
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
