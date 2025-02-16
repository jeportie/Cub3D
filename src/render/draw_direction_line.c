/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_direction_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:15:53 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 13:33:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../class/player.h"
#include "../../include/colors.h"

int	draw_direction_line(t_player *player, int center_x, int center_y, t_image *img)
{
	int	line_length;
	int	i;
	int	lx;
	int	ly;

	line_length = 15;
	i = 0;
	while (i < line_length)
	{
		lx = center_x + (int)(player->dx * i);
		ly = center_y + (int)(player->dy * i);
		put_pixel_to_image(img, lx, ly, PURPLE);
		i++;
	}
	return (0);
}
