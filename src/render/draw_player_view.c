/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:08:08 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 17:08:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/engine.h"
#include "../../include/colors.h"
#include "../../include/compute.h"
#include "../../include/render.h"

int	draw_player_view(t_data *data, t_image *img)
{
	const float			fov = FOV_DEGREES * (M_PI / 180.0f);
	float				start_angle;
	t_ray				ray;
	t_render_context	ctx;
	int					i;
	int					index = 0;
	int					problem_ray[300];

	ft_bzero(problem_ray, 300);
	ctx.prev_wall = WALL_NONE;
	ctx.old_wall_height = 0;
	draw_background(img);
	start_angle = normalize_angle(data->player.angle - (fov / 2));
	i = 0;
	while (i < RAYS)
	{
		ray.angle = normalize_angle(start_angle + i * (fov / (RAYS - 1)));
		ray.vertical = cast_vertical_ray(data, ray.angle);
		ray.horizontal = cast_horizontal_ray(data, ray.angle);
		if (ray.vertical.dist < ray.horizontal.dist)
		{
			ray.chosen = ray.vertical;
			ray.current_wall = WALL_VERTICAL;
			ray.chosen.color = RED;
		}
		else
		{
			ray.chosen = ray.horizontal;
			ray.current_wall = WALL_HORIZONTAL;
			ray.chosen.color = GOLD;
		}
		ray.corrected_distance = correct_fisheye(data->player.angle, ray.angle, ray.chosen.dist);
		ray.wall_height = calculate_wall_height(ray.corrected_distance, fov);
		ctx.line_offset = (THREE_D_HEIGHT / 2) - (ray.wall_height / 2);
		ctx.x_screen = THREE_D_X + (i * THREE_D_WIDTH) / RAYS;
		if (draw_wall_slice(&ray, &ctx, &ctx.prev_wall, &ctx.old_wall_height, img))
		{
			problem_ray[index] = i - 1;
			index++;
		}
		ctx.prev_wall = ray.current_wall;
		ctx.old_wall_height = ray.wall_height;
		i++;
	}
	index = 0;
	while (problem_ray[index])
	{
		i = problem_ray[index];
		ray.angle = normalize_angle(start_angle + i * (fov / (RAYS - 1)));
		ray.vertical = cast_vertical_ray(data, ray.angle);
		ray.horizontal = cast_horizontal_ray(data, ray.angle);
		if (ray.vertical.dist < ray.horizontal.dist)
		{
			ray.chosen = ray.vertical;
			ray.current_wall = WALL_VERTICAL;
			ray.chosen.color = RED;
		}
		else
		{
			ray.chosen = ray.horizontal;
			ray.current_wall = WALL_HORIZONTAL;
			ray.chosen.color = GOLD;
		}
		ray.corrected_distance = correct_fisheye(data->player.angle, ray.angle, ray.chosen.dist);
		ray.wall_height = calculate_wall_height(ray.corrected_distance, fov);
		ctx.line_offset = (THREE_D_HEIGHT / 2) - (ray.wall_height / 2);
		ctx.x_screen = THREE_D_X + (i * THREE_D_WIDTH) / RAYS;

		int	y;
		for (y = 0; y < ray.wall_height; y++)
			put_pixel_to_image(img, ctx.x_screen, y + ctx.line_offset, BLACK);
		ctx.prev_wall = ray.current_wall;
		ctx.old_wall_height = ray.wall_height;
		index++;
	}
	return (0);
}
