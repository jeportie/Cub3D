/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:08:08 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 15:56:45 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/engine.h"
#include "../../include/colors.h"
#include "../../include/compute.h"
#include "../../include/render.h"

void	process_ray(t_data *data, t_ray *ray, float start_angle, int i, float fov)
{
	ray->angle = normalize_angle(start_angle + (i * (fov / (RAYS - 1))));
	if (data->toogle_dda == true)
	{
		ray->chosen = cast_ray_dda(data, ray->angle);
		if (ray->chosen.map_index == 0)
		{
			ray->current_wall = WALL_VERTICAL;
			ray->chosen.color = RED;
		}
		else
		{
			ray->current_wall = WALL_HORIZONTAL;
			ray->chosen.color = GOLD;
		}
	}
	else
	{
		ray->vertical = cast_vertical_ray(data, ray->angle);
		ray->horizontal = cast_horizontal_ray(data, ray->angle);
		if (ray->vertical.dist < ray->horizontal.dist)
		{
			ray->chosen = ray->vertical;
			ray->current_wall = WALL_VERTICAL;
			ray->chosen.color = RED;
		}
		else
		{
			ray->chosen = ray->horizontal;
			ray->current_wall = WALL_HORIZONTAL;
			ray->chosen.color = GOLD;
		}
	}
	ray->corrected_distance = correct_fisheye(data->player.angle,
			ray->angle, ray->chosen.dist);
	calculate_wall_height(ray);
	ray->line_offset = (THREE_D_HEIGHT / 2) - (ray->wall_height / 2);
	ray->x_screen = THREE_D_X + ((i * THREE_D_WIDTH) / RAYS);
}

int	draw_player_view(t_data *data, t_image *img)
{
	const float	fov = FOV_DEGREES * (M_PI / 180.0f);
	float		start_angle = normalize_angle(data->player.angle - (fov / 2));
	t_ray		ray;
	t_rndr_ctx	ctx = {0};
	int			problem_ray[300];
	int			y;
	int			i = 0;
	int			index = 0;

	ft_bzero(problem_ray, sizeof(problem_ray));
	ctx.prev_wall = WALL_NONE;
	ctx.old_wall_height = 0;
	ctx.prev_tile_x = -1;
	ctx.prev_tile_y = -1;
	draw_background(data, img);
	while (i < RAYS)
	{
		process_ray(data, &ray, start_angle, i, fov);
		if (draw_wall_slice(data, &ray, &ctx, img))
		{
			problem_ray[index] = i - 1;
			index++;
		}
		i++;
	}
	index = 0;
	while (problem_ray[index])
	{
		i = problem_ray[index];
		process_ray(data, &ray, start_angle, i, fov);
		y = 0;
		while (y < ray.wall_height)
		{
			put_pixel_to_image(img, ray.x_screen, y + ray.line_offset, BLACK);
			y++;
		}
		index++;
	}
	return (0);
}
