/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:06:17 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/27 01:33:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/engine.h"
#include "../../include/colors.h"
#include "../../include/render.h"

int	draw_wall_slice(t_ray *ray, t_rndr_ctx *ctx, t_image *img)
{
	int	is_incomplete;
	int	y;

	y = 0;
	is_incomplete = 0;
	while (y < ray->wall_height)
	{
		if (y == 0 || y == ray->wall_height - 1)
		{
			put_pixel_to_image(img, ray->x_screen, y + ray->line_offset, BLACK);
		}
		else if ((int)ray->current_wall != ctx->prev_wall
			|| abs(ctx->old_wall_height - ray->wall_height) > 50)
		{
			if (ctx->old_wall_height - ray->wall_height > 50)
			{
				is_incomplete = 1;
				put_pixel_to_image(img, ray->x_screen, y + ray->line_offset,
					ray->chosen.color);
			}
			else
				put_pixel_to_image(img, ray->x_screen, y + ray->line_offset,
					BLACK);
		}
		else
		{
			put_pixel_to_image(img, ray->x_screen, y + ray->line_offset,
				ray->chosen.color);
		}
		y++;
	}
	ctx->prev_wall = ray->current_wall;
	ctx->old_wall_height = ray->wall_height;
	return (is_incomplete);
}
