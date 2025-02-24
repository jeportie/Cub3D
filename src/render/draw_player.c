/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:17:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:47:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"

int	draw_player(t_data *data, t_image *img)
{
	t_coord	center;
	t_coord	start;
	t_coord	dir;

	center.x = (int)data->player.pose.x;
	center.y = (int)data->player.pose.y;
	start.x = center.x - ((float)SQUARE_SIZE / 2);
	start.y = center.y - ((float)SQUARE_SIZE / 2);
	draw_filled_square(start, SQUARE_SIZE, RED, img);
	dir.x = data->player.pose.dx;
	dir.y = data->player.pose.dy;
	draw_direction_line(dir, center, PURPLE, img);
	return (0);
}
