/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:18:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:44:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/engine.h"
#include "../../include/render.h"

int	draw_line(t_coord start, t_coord end, int color, t_image *img)
{
	t_line_vars	line;

	line.dir.x = end.x - start.x;
	line.dir.y = end.y - start.y;
	if (fabs(line.dir.x) > fabs(line.dir.y))
		line.steps = fabs(line.dir.x);
	else
		line.steps = fabs(line.dir.y);
	if (line.steps == 0)
	{
		put_pixel_to_image(start, color, img);
		return (0);
	}
	line.inc.x = (float)line.dir.x / (float)line.steps;
	line.inc.y = (float)line.dir.y / (float)line.steps;
	line.cur.x = start.x;
	line.cur.y = start.y;
	line.i = -1;
	while (++line.i <= line.steps)
	{
		put_pixel_to_image(line.cur, color, img);
		line.cur.x += line.inc.x;
		line.cur.y += line.inc.y;
	}
	return (0);
}
