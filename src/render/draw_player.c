/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:17:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 20:35:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../class/player.h"

int	draw_player(t_player *player, t_image *img)
{
	int	center_x;
	int	center_y;
	int	x_start;
	int	y_start;

	center_x = (int)player->transform.x;
	center_y = (int)player->transform.y;
	x_start = center_x - (SQUARE_SIZE / 2);
	y_start = center_y - (SQUARE_SIZE / 2);
	draw_square(x_start, y_start, img);
	draw_direction_line(player, center_x, center_y, img);
	return (0);
}
