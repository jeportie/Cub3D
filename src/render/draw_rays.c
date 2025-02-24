/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:20:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:48:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/colors.h"
#include "../../include/compute.h"
#include "../../include/render.h"

int	draw_rays(t_data *data, t_image *img)
{
	int			i;
	float		fov;
	float		start_angle;
	float		ray_angle;
	t_rayinfo	chosen;
	t_coord		start;
	t_coord		end;
	int			color;

	fov = FOV_DEGREES * (M_PI / 180.0f);
	start_angle = data->player.pose.angle - (fov / 2);
	i = 0;
	while (i < RAYS)
	{
		ray_angle = start_angle + i * (fov / (RAYS - 1));
		ray_angle = normalize_angle(ray_angle);
		chosen = cast_ray_dda(data, ray_angle);
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
		start.x = (int)data->player.pose.x;
		start.y = (int)data->player.pose.y;
		end.x = (int)chosen.rx;
		end.y = (int)chosen.ry;
		draw_line(start, end, color, img);
		i++;
	}
	return (0);
}
