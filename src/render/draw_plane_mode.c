/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:12:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/31 09:59:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"
#include "../../include/raycast.h"
#include "../../include/cub3d.h"
#include "../../include/engine.h"
#include "../../include/colors.h"

int	calculate_plane_wall_height(float distance_in_tiles)
{
	float	line_height;

	line_height = (float)THREE_D_HEIGHT / distance_in_tiles;
	if (line_height > THREE_D_HEIGHT)
		line_height = THREE_D_HEIGHT;
	return ((int)line_height);
}

int	draw_plane_mode(t_data *data, t_image *img)
{
	double		cameraX;
	double		ray_dir_x;
	double		ray_dir_y;
	int			wall_height;
	int			line_offset;
	t_rayinfo	rayinfo;
	int			color;
	int			x;
	int			y;
	int			drawY;

	draw_background(img);
	x = 0;
	while (x < RAYS)
	{
		cameraX = 2.0 * x / (double)RAYS - 1.0;
		ray_dir_x = data->player.dx + data->player.plane_x * cameraX;
		ray_dir_y = data->player.dy + data->player.plane_y * cameraX;
		rayinfo = cast_ray_dda_plane(data, ray_dir_x, ray_dir_y);
		wall_height = calculate_plane_wall_height(rayinfo.dist);
		line_offset = (THREE_D_HEIGHT / 2) - (wall_height / 2);
		if (rayinfo.map_index == 1)
			color = GOLD;
		else
			color = RED;
		y = 0;
		while (y < wall_height)
		{
			drawY = y + line_offset;
			if (drawY >= 0 && drawY < THREE_D_HEIGHT)
				put_pixel_to_image(img, THREE_D_X + x, drawY, color);
			y++;
		}
		x++;
	}
	return (0);
}
