/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:10:04 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/05 17:26:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cub3d.h"

double	get_time_in_seconds(struct timespec ts);
int		init_image(t_data *data);
int		init_texture(t_data *data);
int		put_pixel_to_image(t_image *img, int x, int y, int color);
int		clear_image(t_image *img, int color);

#endif
