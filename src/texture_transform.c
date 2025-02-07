/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <youremail@example.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:00:00 by yourname          #+#    #+#             */
/*   Updated: 2025/02/07 14:06:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/render.h"
#include "../include/define.h"
#include "../include/engine.h"

int	get_texture_color(t_image *texture, int x, int y)
{
	int	*pixels;
	int	line_pixels;
	int	index;

	pixels = (int *)texture->addr;
	line_pixels = texture->line_len / BPP;
	index = y * line_pixels + x;
	return (pixels[index]);
}

int	texture_transform(t_image *texture, t_ray *ray, t_image *img)
{
	t_tex	tr;

	tr.full_height = ray->true_wall_height;
	tr.ty_step = 32.0f / tr.full_height;
	tr.ty_off = 0.0f;
	tr.clamped_height = ray->wall_height;
	if (tr.full_height > THREE_D_HEIGHT)
		tr.ty_off = (tr.full_height - THREE_D_HEIGHT) / 2.0f;
	tr.tx = 0;
	if (ray->current_wall == WALL_VERTICAL)
		tr.tx = ((int)ray->chosen.ry) % TILE_SIZE;
	else
		tr.tx = ((int)ray->chosen.rx) % TILE_SIZE;
	tr.ty = tr.ty_off * tr.ty_step;
	tr.y = 0;
	while (tr.y < tr.clamped_height)
	{
		tr.tex_y = (int)tr.ty;
		if (tr.tex_y < 0)
			tr.tex_y = 0;
		if (tr.tex_y >= TILE_SIZE)
			tr.tex_y = TILE_SIZE - 1;
		tr.color = get_texture_color(texture, tr.tx, tr.tex_y);
		put_pixel_to_image(img, ray->x_screen, tr.y + ray->line_offset, tr.color);
		tr.ty += tr.ty_step;
		tr.y++;
	}
	return (0);
}
