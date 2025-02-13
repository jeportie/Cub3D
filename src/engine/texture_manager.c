/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:15:29 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/13 18:23:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_manager.h"
#include "raycaster.h"

int	init_texture(t_graphics *engine)
{
	int	width;
	int	height;

	engine->texture.img_ptr
		= mlx_xpm_file_to_image(engine->app->mlx_ptr, TEXTURE, &width, &height);
	if (!engine->texture.img_ptr)
	{
		ft_dprintf(2, ERR_MLX_TEX, TEXTURE);
		return (1);
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		ft_printf(WARN_NOEQUAL, width, height, TILE_SIZE, TILE_SIZE);
	}
	engine->texture.addr = mlx_get_data_addr(engine->texture.img_ptr,
			&engine->texture.bpp,
			&engine->texture.line_len,
			&engine->texture.endian);
	return (0);
}

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
