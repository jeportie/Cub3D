/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:35:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 07:27:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/render.h"
#include "../include/define.h"
#include "../include/engine.h"

int	get_texture_color(t_image *texture, t_coord pos)
{
	int	*pixels;
	int	line_pixels;
	int	index;

	pixels = (int *)texture->addr;
	line_pixels = texture->line_len / BPP;
	index = pos.y * line_pixels + pos.x;
	return (pixels[index]);
}

int	init_tr(t_tex *tr, t_ray *ray)
{
	tr->full_height = ray->true_wall_height;
	tr->ty_step = TILE_SIZE / tr->full_height;
	tr->ty_off = 0.0f;
	tr->clamped_height = ray->wall_height;
	if (tr->full_height > THREE_D_HEIGHT)
		tr->ty_off = (tr->full_height - THREE_D_HEIGHT) / 2.0f;
	tr->tex.x = 0;
	if (ray->current_wall == WALL_VERTICAL)
		tr->tex.x = ((int)ray->chosen.ry) % TILE_SIZE;
	else
		tr->tex.x = ((int)ray->chosen.rx) % TILE_SIZE;
	tr->ty = tr->ty_off * tr->ty_step;
	tr->y = 0;
	return (0);
}

int	texture_transform(t_image *texture, t_ray *ray, t_image *img)
{
	t_tex	tr;
	t_coord	pos;

	init_tr(&tr, ray);
	while (tr.y < tr.clamped_height)
	{
		tr.tex.y = (int)tr.ty;
		if (tr.tex.y < 0)
			tr.tex.y = 0;
		if (tr.tex.y >= TILE_SIZE)
			tr.tex.y = TILE_SIZE - 1;
		tr.color = get_texture_color(texture, tr.tex);
		pos.x = ray->x_screen;
		pos.y = tr.y + ray->line_offset;
		put_pixel_to_image(pos, tr.color, img);
		tr.ty += tr.ty_step;
		tr.y++;
	}
	return (0);
}
