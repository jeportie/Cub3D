/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:39:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/10 21:23:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_ENGINE_H
# define GRAPHIC_ENGINE_H

# include "game.h"

typedef struct s_graphic_engine_api
{
	t_game_api	base;
}				t_graphic_engine_api;

extern const t_graphic_engine_api	g_graphic_engine_methods;

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
	int				current_img;
	t_image			buffer[2];
	t_image			texture;
	struct timespec	last_time;
	double			delta_accumulator;
}				t_graphics;

typedef struct s_graphic_engine
{
	t_game						base;

	const t_graphic_engine_api	*methods;
}				t_graphic_engine;

typedef struct s_line_data
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line_data;

/* ~~~~~~~~~~~ GRAPHIC ENGINE METHODS ~~~~~~~~~~~~~*/
t_graphic_engine	*create_graphic_engine(void);
int					init_graphic_engine(t_graphic_engine *graphic_engine);
int					destroy_graphic_engine(t_graphic_engine *graphic_engine);
//3D
int					draw_background(t_image *img);
int					draw_player_view(t_game *game, t_image *img);
//minimap
int					draw_tile(int row, int col, int base_color, t_image *img);
int					draw_map(t_image *img);
int					draw_square(int x_start, int y_start, t_image *img);
int					draw_direction_line(t_game *game, int center_x, int center_y, t_image *img);
int					draw_player(t_game *game, t_image *img);
int					draw_line(t_line_data ldata, t_image *img);
int					draw_rays(t_game *game, t_image *img);
int					draw_angle_mode(t_game *game, t_image *img);

int					init_image(t_game *game);
int					put_pixel_to_image(t_image *img, int x, int y, int color);
int					clear_image(t_image *img, int color);

#endif
