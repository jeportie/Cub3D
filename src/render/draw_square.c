/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:14:49 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/19 18:57:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../../include/colors.h"
#include "../../include/colors.h"

int	draw_square(t_coord start, t_image *img)
{
	int	row;
	int	col;
	int	draw_col;
	int	draw_row;

	row = 0;
	while (row < SQUARE_SIZE)
	{
		col = 0;
		while (col < SQUARE_SIZE)
		{
			draw_col = start.x + col;
			draw_row = start.y + row;
			put_pixel_to_image(img, draw_col, draw_row, RED);
			col++;
		}
		row++;
	}
	return (0);
}
