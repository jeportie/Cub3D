/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:15:18 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/18 15:31:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

typedef struct s_line_data
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line_data;

//3D view	
int			draw_background(t_game *game, t_image *img);
int			draw_skybox(t_game *game, t_image *img);
int			draw_walls(t_game *game, t_image *img);

//2D view
int			draw_map(t_map *map, t_image *img);
int			draw_player(t_player *player, t_image *img);
int			draw_tile(int row, int col, int base_color, t_image *img);
int			draw_square(int x_start, int y_start, t_image *img);
int			draw_direction_line(t_transform transform, int center_x,
				int center_y, t_image *img);
int			draw_line(t_line_data ldata, t_image *img);
int			draw_rays(t_game *game, t_image *img);
//int			draw_angle_mode(t_game *game, t_image *img);

int			draw_minimap_tile(t_image *img, int x_start, int y_start,
				int size, int base_color);

#endif /*RENDER_H*/
