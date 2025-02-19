/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:15:18 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/19 19:06:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

//3D view	
int	draw_background(t_game *game, t_image *img);
int	draw_skybox(t_game *game, t_image *img);
int	draw_walls(t_game *game, t_image *img);

//2D view
int	draw_map(t_map *map, t_image *img);
int	draw_player(t_player *player, t_image *img);
int	draw_tile(int row, int col, int base_color, t_image *img);
int	draw_rays(t_game *game, t_image *img);

// HUD
int	draw_minimap_tile(t_image *img, t_coord start, int size, int base_color);

//GEOMETRY TOOLS
int	draw_line(t_coord start, t_coord stop, int color, t_image *img);
int	draw_square(t_coord start, t_image *img);
int	draw_direction_line(t_transform transform, t_coord center, t_image *img);
int	draw_filled_circle(t_coord center, int radius, int color, t_image *img);

#endif /*RENDER_H*/
