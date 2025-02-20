/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:14:49 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:40:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../../include/colors.h"
#include "../../include/colors.h"

int	draw_square(t_coord start, t_image *img)
{
	int		row;
	int		col;
	t_coord	pos;

	row = 0;
	while (row < SQUARE_SIZE)
	{
		col = 0;
		while (col < SQUARE_SIZE)
		{
			pos.x = start.x + col;
			pos.y = start.y + row;
			put_pixel_to_image(pos, RED, img);
			col++;
		}
		row++;
	}
	return (0);
}
