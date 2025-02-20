/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_filled_cercle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:34:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:27:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"

int	draw_filled_circle(t_coord center, int radius, int color, t_image *img)
{
	t_coord	index;
	t_coord	pos;

	index.y = -radius;
	while (index.y <= radius)
	{
		index.x = -radius;
		while (index.x <= radius)
		{
			if (index.x * index.x + index.y * index.y <= radius * radius)
			{
				pos.x = center.x + index.x;
				pos.y = center.y + index.y;
				put_pixel_to_image(pos, color, img);
			}
			index.x++;
		}
		index.y++;
	}
	return (0);
}
