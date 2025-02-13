/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:14:49 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 13:31:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../../include/colors.h"
#include "../../include/colors.h"

int	draw_square(int x_start, int y_start, t_image *img)
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
			draw_col = x_start + col;
			draw_row = y_start + row;
			put_pixel_to_image(img, draw_col, draw_row, RED);
			col++;
		}
		row++;
	}
	return (0);
}
