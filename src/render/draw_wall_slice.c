/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:06:17 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 17:07:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/engine.h"
#include "../../include/colors.h"
#include "../../include/render.h"

int	draw_wall_slice(t_ray *ray, t_render_context *ctx, int *prev_wall, int *old_wall_height, t_image *img)
{
	int	y;
	int	is_incomplete;

	is_incomplete = 0;
	for (y = 0; y < ray->wall_height; y++)
	{
		if (y == 0 || y == ray->wall_height - 1)
			put_pixel_to_image(img, ctx->x_screen, y + ctx->line_offset, BLACK);
		else
		{
			if ((int)ray->current_wall != *prev_wall || abs(*old_wall_height - ray->wall_height) > 20)
			{
				if (*old_wall_height - ray->wall_height > 20)
				{
					is_incomplete = 1;
					put_pixel_to_image(img, ctx->x_screen, y + ctx->line_offset, ray->chosen.color);
				}
				else
					put_pixel_to_image(img, ctx->x_screen, y + ctx->line_offset, BLACK);
			}
			else
				put_pixel_to_image(img, ctx->x_screen, y + ctx->line_offset, ray->chosen.color);
		}
	}
	return (is_incomplete);
}
