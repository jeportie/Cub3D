/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_direction_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:15:53 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:32:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"
#include "../../include/render.h"

int	draw_direction_line(t_coord pos, t_coord dir, int color, t_image *img)
{
	int		line_length;
	int		i;
	t_coord	l;

	line_length = 15;
	i = 0;
	while (i < line_length)
	{
		l.x = pos.x + (int)(dir.x * i);
		l.y = pos.y + (int)(dir.y * i);
		put_pixel_to_image(l, color, img);
		i++;
	}
	return (0);
}
