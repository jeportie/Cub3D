/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:14:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/20 10:19:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_engine.h"
#include "texture_manager.h"
#include "../class/game.h"
#include "../class/settings.h"
#include "core_engine.h"

t_graphics	*create_graphic_engine(void)
{
	t_graphics	*engine;

	ft_printf(DEB_GRAPHIC_CREATE);
	engine = gc_malloc(sizeof(t_graphics));
	if (!engine)
		return (NULL);
	return (engine);
}

int	put_pixel_to_image(t_coord coord, int color, t_image *img)
{
	char	*dst;

	if (coord.x < 0 || coord.x >= WINDOW_WIDTH
		|| coord.y < 0 || coord.y >= WINDOW_HEIGHT)
		return (-1);
	dst = img->addr + ((int)coord.y * img->line_len + (int)coord.x * (img->bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	clear_image(t_image *img, int color)
{
	t_coord	pos;

	pos.y = 0;
	while (pos.y < WINDOW_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WINDOW_WIDTH)
		{
			put_pixel_to_image(pos, color, img);
			pos.x++;
		}
		pos.y++;
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
	if (init_skybox(engine, SKYBOX))
	{
		ft_dprintf(2, "Failed to load skybox.xpm\n");
		return (1);
	}

	ft_printf(DEB_GRAPHIC_INIT);
	return (0);
}

int	graphic_engine_draw_frame(t_game *game, t_graphics *engine)
{
	int				buffer_to_draw;
	int				i;
	t_image			*img;
	t_game_object	*object;

	buffer_to_draw = (engine->current_img + 1) % 2;
	img = &engine->buffer[buffer_to_draw];
	clear_image(img, BLACK);
	i = 0;
	while (i < game->object_count)
	{
		object = game->objects[i];
		if (object && object->active && object->methods->render)
			object->methods->render(object, game, buffer_to_draw);
		i++;
	}
	mlx_put_image_to_window(engine->app->mlx_ptr, engine->app->win_ptr,
		img->img_ptr, 0, 0);
	draw_debug_log(engine->app->mlx_ptr, engine->app->win_ptr,
		&game->debug_log);
	char fps_str[64];
	snprintf(fps_str, sizeof(fps_str), "FPS: %.2f", game->time_state->last_fps);
	mlx_string_put(engine->app->mlx_ptr, engine->app->win_ptr,
			20, 620, 0xFFFFFF, fps_str);
	mlx_string_put(engine->app->mlx_ptr, engine->app->win_ptr,
			20, 640, 0xFFFFFF, "[DDA-ANGLE RAYCASTER]");
	engine->current_img = buffer_to_draw;
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
