/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:17:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/31 13:59:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"
#include "../../include/engine.h"

int	draw_player(t_data *data, t_image *img)
{
	int	center_x;
	int	center_y;
	int	x_start;
	int	y_start;

	center_x = (int)data->player.x;
	center_y = (int)data->player.y;
	x_start = center_x - (SQUARE_SIZE / 2);
	y_start = center_y - (SQUARE_SIZE / 2);
	draw_square(x_start, y_start, img);
	draw_direction_line(data, center_x, center_y, img);
	return (0);
}

int draw_player_plane(t_data *data, t_image *img)
{
	int	center_x;
	int	center_y;
	int	x_start;
	int	y_start;
	int	dir_length;
	int	i;
	int	lx;
	int	ly;
	int plane_length;

	center_x = (int)(data->player.x * TILE_SIZE);
	center_y = (int)(data->player.y * TILE_SIZE);
	x_start = center_x - (SQUARE_SIZE / 2);
	y_start = center_y - (SQUARE_SIZE / 2);
	draw_square(x_start, y_start, img);
	dir_length = 20;
	i = 0;
	while (i < dir_length)
	{
		lx = center_x + (int)(data->player.dx * i);
		ly = center_y + (int)(data->player.dy * i);
		put_pixel_to_image(img, lx, ly, PURPLE);
		i++;
	}
	plane_length = 20;
	i = 0;
	while (i < plane_length)
	{
		lx = center_x + (int)(data->player.plane_x * i);
		ly = center_y + (int)(data->player.plane_y * i);
		put_pixel_to_image(img, lx, ly, CYAN);
		i++;
	}
	i = 0;
	while (i < plane_length)
	{
		lx = center_x - (int)(data->player.plane_x * i);
		ly = center_y - (int)(data->player.plane_y * i);
		put_pixel_to_image(img, lx, ly, CYAN);
		i++;
	}
	return (0);
}
