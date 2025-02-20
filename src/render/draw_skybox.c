/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:46:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:39:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../class/player.h"
#include "../engine/texture_manager.h" 

int	draw_skybox(t_game *game, t_image *img)
{
	t_graphics	*g;
	t_player	*p;
	t_coord		pos;
	int			sky_w;
	int			sky_h;
	double		angle_deg;
	int			x_offset;
	int			half_screen;
	int			tx;
	int			ty;
	int			color;

	g = game->graphic_engine;
	p = game->player;
	sky_w = THREE_D_WIDTH;
	sky_h = THREE_D_HEIGHT;
	angle_deg = p->transform.angle * (180.0 / M_PI);
	if (angle_deg < 0)
		angle_deg += 360.0;
	x_offset = (int)((angle_deg / 360.0) * sky_w);
	half_screen = THREE_D_HEIGHT / 2;
	pos.y = 0;
	while (pos.y < half_screen)
	{
		ty = (int)((pos.y / half_screen ) * (sky_h / 2));
		pos.x = THREE_D_X;
		while (pos.x < THREE_D_WIDTH + THREE_D_X)
		{
			tx = (x_offset + (int)pos.x) % sky_w;
			color = get_texture_color(&g->skybox, tx, ty);
			put_pixel_to_image(pos, color, img);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
