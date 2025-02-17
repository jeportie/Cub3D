/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:39:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/17 12:10:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_ENGINE_H
# define GRAPHIC_ENGINE_H

# include "../class/game.h"
# include "../../include/render.h"
# include "../../lib/minilibx/mlx_int.h"

typedef struct s_mlx_app
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx_app;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_graphics
{
	t_mlx_app		*app;
	int				current_img;
	t_image			buffer[2];
	t_image			texture;
	t_image			skybox;
}				t_graphics;

t_mlx_app	*mlx_app_create(int width, int height, const char *title);
t_graphics	*create_graphic_engine(void);
int			graphic_engine_init(t_game *game, t_graphics *engine);
int			graphic_engine_draw_frame(t_game *gmae, t_graphics *engine);
int			graphic_engine_shutdown(t_graphics *engine);

int			put_pixel_to_image(t_image *img, int x, int y, int color);
int			clear_image(t_image *img, int color);

#endif
