/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:06:17 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 08:30:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/engine.h"
#include "../../include/render.h"

int	paint_wall(t_ray *ray, t_image *img)
{
	int		y;
	t_coord	pos;

	pos.x = ray->x_screen;
	y = (int)ray->line_offset;
	while (y < ray->line_offset + ray->wall_height)
	{
		pos.y = y;
		put_pixel_to_image(pos, ray->chosen.color, img);
		y++;
	}
	return (0);
}

int	draw_wall_slice(t_data *data, t_ray *ray, t_image *img)
{
	if (data->toogle_texture_mode)
	{
		if (ray->current_wall == WALL_HORIZONTAL)
		{
			if (sinf(ray->angle) < 0.0f)
				texture_transform(&data->walls[0], ray, img);
			else
				texture_transform(&data->walls[1], ray, img);
		}
		else
		{
			if (cosf(ray->angle) > 0.0f)
				texture_transform(&data->walls[2], ray, img);
			else
				texture_transform(&data->walls[3], ray, img);
		}
	}
	else
		paint_wall(ray, img);
	return (0);
}
