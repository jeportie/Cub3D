/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:18:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 17:19:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/engine.h"
#include "../../include/render.h"

int	draw_line(t_line_data ldata, t_image *img)
{
	t_line_vars	line;

	line.dx = ldata.x1 - ldata.x0;
	line.dy = ldata.y1 - ldata.y0;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	if (line.steps == 0)
	{
		put_pixel_to_image(img, ldata.x0, ldata.y0, ldata.color);
		return (0);
	}
	line.inc_x = (float)line.dx / (float)line.steps;
	line.inc_y = (float)line.dy / (float)line.steps;
	line.cur_x = ldata.x0;
	line.cur_y = ldata.y0;
	line.i = 0;
	while (line.i <= line.steps)
	{
		put_pixel_to_image(img, (int)line.cur_x,
			(int)line.cur_y, ldata.color);
		line.cur_x += line.inc_x;
		line.cur_y += line.inc_y;
		line.i++;
	}
	return (0);
}
