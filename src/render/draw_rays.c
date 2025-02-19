/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:20:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/19 18:47:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/graphic_engine.h"
#include "../engine/raycaster.h"
#include "../class/settings.h"
#include "../class/player.h"
#include "../../include/colors.h"
#include "../../include/compute.h"

int	draw_rays(t_game *game, t_image *img)
{
	int			i;
	const float	fov = FOV_DEGREES * (M_PI / 180.0f);
	float		start_angle;
	float		ray_angle;
	t_rayinfo	vertical_ray;
	t_rayinfo	horizontal_ray;
	t_rayinfo	chosen;
	int			color;
	t_coord		start;
	t_coord		end;

	start_angle = game->player->transform.angle - (fov / 2);
	i = 0;
	while (i < RAYS)
	{
		ray_angle = start_angle + i * (fov / (RAYS - 1));
		ray_angle = normalize_angle(ray_angle);
		if (game->settings->toogle_dda == true)
		{
			chosen = cast_ray_dda(game, ray_angle);
			if (chosen.map_index == 0)
			{
				if (cosf(ray_angle) > 0.0f)
					color = ORANGE;
				else
					color = YELLOW;
			}
			else
			{
				if (sinf(ray_angle) > 0.0f)
					color = LIGHTGREEN;
				else
					color = DARKGREEN;
			}
		}
		else
		{
			vertical_ray = cast_vertical_ray(game, ray_angle);
			horizontal_ray = cast_horizontal_ray(game, ray_angle);
			if (vertical_ray.dist < horizontal_ray.dist)
			{
				color = GREEN;
				chosen = vertical_ray;
			}
			else
			{
				color = LIGHTGREEN;
				chosen = horizontal_ray;
			}
		}
		start.x = (int)game->player->transform.x;
		start.y = (int)game->player->transform.y;
		end.x = (int)chosen.rx;
		end.y = (int)chosen.ry;
		draw_line(start, end, color, img);
		i++;
	}
	return (0);
}
