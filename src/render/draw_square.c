/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:14:49 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:57:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

int	draw_filled_square(t_coord start, float size, int color, t_image *img)
{
	int		row;
	int		col;
	t_coord	draw;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			draw.x = start.x + col;
			draw.y = start.y + row;
			put_pixel_to_image(draw, color, img);
			col++;
		}
		row++;
	}
	return (0);
}
