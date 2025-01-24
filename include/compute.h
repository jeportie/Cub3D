/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:23:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 16:30:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

# include "cub3d.h"

float	normalize_angle(float angle);
float	correct_fisheye(float player_angle, float ray_angle, float distance);
int		calculate_wall_height(float distance, float fov);;
float	get_safe_cos(float angle);
float	get_safe_sin(float angle);
float	calculate_intercept(float player_pos, int flag, char mode);
float	calculate_tan_a(float sin_a, float cos_a);
float	calculate_step_primary(int flag, float tile_size);
float	calculate_step_secondary(float step_primary, float tan_a);
float	calculate_distance(float delta_x, float delta_y);

#endif
