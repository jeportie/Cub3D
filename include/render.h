/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:04:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 17:04:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "raycast.h"

typedef struct s_tex
{
	float	full_height;
	float	ty_step;
	float	ty_off;
	float	ty;
	int		y;
	int		tx;
	int		tex_y;
	int		color;
	int		clamped_height;
}	t_tex;

//3D
int	draw_background(t_data *data, t_image *img);
int	draw_player_view(t_data *data, t_image *img);
int	draw_wall_slice(t_data *data, t_ray *ray, t_rndr_ctx *ctx, t_image *img);

//minimap
int	draw_tile(int row, int col, int base_color, t_image *img);
int	draw_map(t_data *data, t_image *img);
int	draw_square(int x_start, int y_start, t_image *img);
int	draw_direction_line(t_data *data, int center_x, int center_y, t_image *img);
int	draw_player(t_data *data, t_image *img);
int	draw_line(t_line_data ldata, t_image *img);
int	draw_rays(t_data *data, t_image *img);
int	draw_angle_mode(t_data *data, t_image *img);
int	texture_transform(t_image *texture, t_ray *ray, t_image *img);

#endif
