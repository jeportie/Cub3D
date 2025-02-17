/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:01:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/17 13:09:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../engine/graphic_engine.h"
#include "../../include/colors.h"

int	draw_background(t_game *game, t_image *img)
{
	int	x;
	int	y;

	(void)game;
	draw_skybox(game, img);
	x = THREE_D_X;
	while (x < WINDOW_WIDTH)
	{
		y = THREE_D_HEIGHT / 2;
		while (y < THREE_D_HEIGHT)
		{
			put_pixel_to_image(img, x, y, DARKKHAKI);
			y++;
		}
		x++;
	}
	return (0);
}
