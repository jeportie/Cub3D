/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:18:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/19 18:42:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../engine/raycaster.h"
#include "../../include/cub3d.h"

int	draw_line(t_coord start, t_coord end, int color, t_image *img)
{
	t_line_vars	line;

	line.dx = end.x - start.x;
	line.dy = end.y - start.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	if (line.steps == 0)
	{
		put_pixel_to_image(img, start.x, start.y, color);
		return (0);
	}
	line.inc_x = (float)line.dx / (float)line.steps;
	line.inc_y = (float)line.dy / (float)line.steps;
	line.cur_x = start.x;
	line.cur_y = start.y;
	line.i = 0;
	while (line.i <= line.steps)
	{
		put_pixel_to_image(img, (int)line.cur_x,
			(int)line.cur_y, color);
		line.cur_x += line.inc_x;
		line.cur_y += line.inc_y;
		line.i++;
	}
	return (0);
}
