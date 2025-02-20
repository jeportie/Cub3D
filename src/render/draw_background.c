/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:01:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:21:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../engine/graphic_engine.h"
#include "../../include/colors.h"

int	draw_background(t_game *game, t_image *img)
{
	t_coord	pos;

	(void)game;
	draw_skybox(game, img);
	pos.x = THREE_D_X;
	while (pos.x < WINDOW_WIDTH)
	{
		pos.y = THREE_D_HEIGHT / 2;
		while (pos.y < THREE_D_HEIGHT)
		{
			put_pixel_to_image(pos, DARKKHAKI, img);
			pos.y++;
		}
		pos.x++;
	}
	return (0);
}
