/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:17:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/19 18:59:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../class/player.h"

int	draw_player(t_player *player, t_image *img)
{
	t_coord	center;
	t_coord	start;

	center.x = (int)player->transform.x;
	center.y = (int)player->transform.y;
	start.x = center.x - (SQUARE_SIZE / 2);
	start.y = center.y - (SQUARE_SIZE / 2);
	draw_square(start, img);
	draw_direction_line(player->transform, center, img);
	return (0);
}
