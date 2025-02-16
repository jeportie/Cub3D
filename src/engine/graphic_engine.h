/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:39:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/16 13:35:04 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_ENGINE_H
# define GRAPHIC_ENGINE_H

# include "../class/game.h"
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
}				t_graphics;

typedef struct s_line_data
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line_data;

t_mlx_app	*mlx_app_create(int width, int height, const char *title);
t_graphics	*create_graphic_engine(void);
int			graphic_engine_init(t_game *game, t_graphics *engine);
int			graphic_engine_draw_frame(t_game *gmae, t_graphics *engine);
int			graphic_engine_shutdown(t_graphics *engine);

int			put_pixel_to_image(t_image *img, int x, int y, int color);
int			clear_image(t_image *img, int color);
//3D	
int			draw_background(t_image *img);
int			draw_walls(t_game *game, t_image *img);
//minimap
int			draw_tile(int row, int col, int base_color, t_image *img);
int			draw_map(t_map *map, t_image *img);
int			draw_square(int x_start, int y_start, t_image *img);
int			draw_direction_line(t_player *player, int center_x, int center_y, t_image *img);
int			draw_player(t_player *player, t_image *img);
int			draw_line(t_line_data ldata, t_image *img);
int			draw_rays(t_game *game, t_image *img);
int			draw_angle_mode(t_game *game, t_image *img);

#endif
