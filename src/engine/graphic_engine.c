/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:14:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 13:38:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_engine.h"
#include "texture_manager.h"
#include "../class/settings.h"

t_graphics	*create_graphic_engine(void)
{
	t_graphics	*engine;

	ft_printf(DEB_GRAPHIC_CREATE);
	engine = gc_malloc(sizeof(t_graphics));
	if (!engine)
		return (NULL);
	return (engine);
}

int	put_pixel_to_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return (-1);
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	clear_image(t_image *img, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int	graphic_engine_init(t_game *game, t_graphics *engine)
{
	int	i;

	i = 0;
	engine->app = mlx_app_create(game->settings->window_width,
			game->settings->window_height, GAME_TITLE);
	if (!engine->app)
	{
		ft_dprintf(2, ERR_GRAPHIC_INIT);
		return (1);
	}
	while (i < 2)
	{
		engine->buffer[i].img_ptr
			= mlx_new_image(engine->app->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
		if (!engine->buffer[i].img_ptr)
		{
			ft_dprintf(2, ERR_MLX_IMAGE);
			exit(1);
		}
		engine->buffer[i].addr = mlx_get_data_addr(engine->buffer[i].img_ptr,
				&engine->buffer[i].bpp,
				&engine->buffer[i].line_len,
				&engine->buffer[i].endian);
		if (!engine->buffer[i].addr)
		{
			ft_dprintf(2, ERR_MLX_DATA);
			exit(1);
		}
		i++;
	}
	engine->current_img = 0;
	if (init_texture(engine))
	{
		ft_dprintf(2, ERR_TEX_INIT);
		return (1);
	}
	ft_printf(DEB_GRAPHIC_INIT);
	return (0);
}

int	graphic_engine_draw_frame(t_game *game, t_graphics *engine)
{
	int				buffer_index;
	int				i;
	t_image			*img;
	t_game_object	*object;

	buffer_index = (engine->current_img + 1) % 2;
	img = &engine->buffer[buffer_index];
	clear_image(img, BLACK);
	i = 0;
	while (i < game->object_count)
	{
		object = game->objects[i];
		if (object && object->active && object->methods->render)
			object->methods->render(object, game);
		i++;
	}
	mlx_put_image_to_window(engine->app->mlx_ptr, engine->app->win_ptr,
		img->img_ptr, 0, 0);
	engine->current_img = buffer_index;
	return (0);
}

int	graphic_engine_shutdown(t_graphics *engine)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (engine->buffer[i].img_ptr)
			mlx_destroy_image(engine->app->mlx_ptr,
				engine->buffer[i].img_ptr);
		i++;
	}
	return (0);
}
