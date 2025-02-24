/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:10:04 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 10:25:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cub3d.h"

double	get_time_in_seconds(struct timespec ts);
int		fps_update(t_data *data, double *delta, double *time_step);
int		init_image(t_data *data);
int		init_wall_texture(t_data *data);

int		put_pixel_to_image(t_coord pos, int colot, t_image *img);
int		clear_image(t_image *img, int color);

#endif
