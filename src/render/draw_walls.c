/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:59:10 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:51:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/settings.h"
#include "../class/player.h"
#include "../engine/raycaster.h"
#include "../../include/colors.h"
#include "../../include/compute.h"

void	process_ray(t_game *game, t_ray *ray, float start_angle, int i, float fov)
{
	ray->angle = normalize_angle(start_angle + (i * (fov / (RAYS - 1))));
	if (game->settings->toogle_dda == true)
	{
		ray->chosen = cast_ray_dda(game, ray->angle);
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
		ray->vertical = cast_vertical_ray(game, ray->angle);
		ray->horizontal = cast_horizontal_ray(game, ray->angle);
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
	ray->corrected_distance = correct_fisheye(game->player->transform.angle,
			ray->angle, ray->chosen.dist);
	calculate_wall_height(ray);
	ray->line_offset = (THREE_D_HEIGHT / 2) - (ray->wall_height / 2);
	ray->x_screen = THREE_D_X + ((i * THREE_D_WIDTH) / RAYS);
}

int	draw_walls(t_game *game, t_image *img)
{
	const float	fov = FOV_DEGREES * (M_PI / 180.0f);
	float		start_angle = normalize_angle(game->player->transform.angle - (fov / 2));
	t_ray		ray;
	t_rndr_ctx	ctx = {0};
	int			problem_ray[300];
	int			y;
	int			i = 0;
	int			index = 0;
	t_coord		pos;

	ft_bzero(problem_ray, sizeof(problem_ray));
	ctx.prev_wall = WALL_NONE;
	ctx.old_wall_height = 0;
	ctx.prev_tile_x = -1;
	ctx.prev_tile_y = -1;
	draw_background(game, img);
	while (i < RAYS)
	{
		process_ray(game, &ray, start_angle, i, fov);
		if (draw_wall_slice(game, &ray, &ctx, img))
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
		process_ray(game, &ray, start_angle, i, fov);
		y = 0;
		while (y < ray.wall_height)
		{
			pos.x = ray.x_screen;
			pos.y = y + ray.line_offset;
			put_pixel_to_image(pos, BLACK, img);
			y++;
		}
		index++;
	}
	return (0);
}
