/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:17:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 17:17:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minimap.h"
#include "../../include/render.h"

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
