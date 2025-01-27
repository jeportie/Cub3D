/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:20:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/27 15:22:27 by jeportie         ###   ########.fr       */
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
	const float	fov = FOV_DEGREES * (M_PI / 180.0f);
	float		start_angle;
	float		ray_angle;
	t_rayinfo	vertical_ray;
	t_rayinfo	horizontal_ray;
	t_rayinfo	chosen;
	t_line_data	ldata;

	start_angle = data->player.angle - (fov / 2);
	i = 0;
	while (i < RAYS)
	{
		ray_angle = start_angle + i * (fov / (RAYS - 1));
		ray_angle = normalize_angle(ray_angle);
		if (data->use_dda == true)
		{
			chosen = cast_ray_dda(data, ray_angle);
			if (chosen.map_index == 0)
			{
				if (cosf(ray_angle) > 0.0f)
					ldata.color = ORANGE;
				else
					ldata.color = YELLOW;
			}
			else
			{
				if (sinf(ray_angle) > 0.0f)
					ldata.color = LIGHTGREEN;
				else
					ldata.color = DARKGREEN;
			}
		}
		else
		{
			vertical_ray = cast_vertical_ray(data, ray_angle);
			horizontal_ray = cast_horizontal_ray(data, ray_angle);
			if (vertical_ray.dist < horizontal_ray.dist)
			{
				ldata.color = GREEN;
				chosen = vertical_ray;
			}
			else
			{
				ldata.color = LIGHTGREEN;
				chosen = horizontal_ray;
			}
		}
		ldata.x0 = (int)data->player.x;
		ldata.y0 = (int)data->player.y;
		ldata.x1 = (int)chosen.rx;
		ldata.y1 = (int)chosen.ry;
		draw_line(ldata, img);
		i++;
	}
	return (0);
}
