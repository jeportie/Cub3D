/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:12:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/05 20:04:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"
#include "../../include/raycast.h"
#include "../../include/cub3d.h"
#include "../../include/colors.h"
#include "../../include/compute.h"

int	draw_plane_mode(t_data *data, t_image *img)
{
	double		cameraX;
	double		ray_dir_x;
	double		ray_dir_y;
	int			x;
	t_rndr_ctx	ctx;
	t_ray		ray;
	t_rayinfo	rayinfo;

	ctx.prev_wall = WALL_NONE;
	ctx.old_wall_height = 0;
	ctx.prev_tile_x = -1;
	ctx.prev_tile_y = -1;
	draw_background(img);
	x = 0;
	while (x < RAYS)
	{
		cameraX = 2.0 * x / (double)RAYS - 1.0;
		ray_dir_x = data->player.dx + data->player.plane_x * cameraX;
		ray_dir_y = data->player.dy + data->player.plane_y * cameraX;
		rayinfo = cast_ray_dda_plane(data, ray_dir_x, ray_dir_y);
		ray.wall_height = calculate_plane_wall_height(rayinfo.dist);
		ray.line_offset = (THREE_D_HEIGHT / 2) - (ray.wall_height / 2);
		ray.x_screen = THREE_D_X + x;
		ray.chosen = rayinfo;
		if (rayinfo.map_index == 1)
			ray.chosen.color = GOLD;
		else
			ray.chosen.color = RED;
		if (rayinfo.map_index == 1)
			ray.current_wall = WALL_VERTICAL;
		else
			ray.current_wall =WALL_HORIZONTAL;
		draw_wall_slice(data, &ray, &ctx, img);
		x++;
	}
	return (0);
}
