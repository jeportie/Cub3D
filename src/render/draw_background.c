/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:01:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 08:28:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/engine.h"

int	draw_filled_rectangle(t_coord pos, t_scale size, int color, t_image *img)
{
	int	x;
	int	y;

	x = pos.x;
	while (x < (int)size.x)
	{
		y = pos.y;
		while (y < (int)size.y)
		{
			put_pixel_to_image((t_coord){x, y}, color, img);
			y++;
		}
		x++;
	}
	return (0);
}

int	draw_background(t_data *data, t_image *img)
{
	t_coord	pos;
	t_scale	size;
	int		color;

	pos.x = THREE_D_X;
	pos.y = 0;
	size.x = WINDOW_WIDTH;
	size.y = (float)THREE_D_HEIGHT / 2;
	color = data->parse.config.ceiling_color;
	draw_filled_rectangle(pos, size, color, img);
	pos.y = (float)THREE_D_HEIGHT / 2;
	size.y = THREE_D_HEIGHT;
	color = data->parse.config.floor_color;
	draw_filled_rectangle(pos, size, color, img);
	return (0);
}
