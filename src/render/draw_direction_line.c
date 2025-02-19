/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_direction_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:15:53 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/19 19:03:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../../include/colors.h"

int	draw_direction_line(t_transform transform, t_coord center, t_image *img)
{
	int	line_length;
	int	i;
	int	lx;
	int	ly;

	line_length = 15;
	i = 0;
	while (i < line_length)
	{
		lx = (int)center.x + (int)(transform.dx * i);
		ly = (int)center.y + (int)(transform.dy * i);
		put_pixel_to_image(img, lx, ly, PURPLE);
		i++;
	}
	return (0);
}
