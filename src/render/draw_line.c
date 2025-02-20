/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:18:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:36:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"

int	draw_line(t_coord start, t_coord end, int color, t_image *img)
{
	t_coord	dist;
	t_coord	inc;
	t_coord	cur;
	int		steps;
	int		i;

	dist.x = end.x - start.x;
	dist.y = end.y - start.y;
	if (abs((int)dist.x) > abs((int)dist.y))
		steps = abs((int)dist.x);
	else
		steps = abs((int)dist.y);
	if (steps == 0)
	{
		put_pixel_to_image(start, color, img);
		return (0);
	}
	inc.x = dist.x / (float)steps;
	inc.y = dist.y / (float)steps;
	cur.x = start.x;
	cur.y = start.y;
	i = 0;
	while (i <= steps)
	{
		put_pixel_to_image(cur, color, img);
		cur.x += inc.x;
		cur.y += inc.y;
		i++;
	}
	return (0);
}
