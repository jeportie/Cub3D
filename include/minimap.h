/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:51:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/20 21:58:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

int	compute_map_offset(t_data *data);
int	print_map(void);
int	draw_map(t_data *data);
int	draw_tile(t_data *data, int row, int col, int base_color);
int	draw_player(t_data *data);
int	draw_square(t_data *data, int x_start, int y_start);
int	draw_direction_line(t_data *data, int center_x, int center_y);

#endif
