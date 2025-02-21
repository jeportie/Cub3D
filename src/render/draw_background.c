/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:01:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 16:48:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/engine.h"

int	draw_background(t_data *data, t_image *img)
{
	int	x;
	int	y;

	x = THREE_D_X;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < THREE_D_HEIGHT / 2)
		{
			put_pixel_to_image(img, x, y, data->parse.config.ceiling_color);
			y++;
		}
		x++;
	}
	x = THREE_D_X;
	while (x < WINDOW_WIDTH)
	{
		y = THREE_D_HEIGHT / 2;
		while (y < THREE_D_HEIGHT)
		{
			put_pixel_to_image(img, x, y, data->parse.config.floor_color);
			y++;
		}
		x++;
	}
	return (0);
}
