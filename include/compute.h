/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:23:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/17 08:48:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

# include "cub3d.h"
# include "../src/engine/raycaster.h"

// Math
float	normalize_angle(float angle);
float	get_safe_cos(float angle);
float	get_safe_sin(float angle);
float	calculate_tan_a(float angle);
float	correct_fisheye(float player_angle, float ray_angle, float distance);
float	calculate_distance(float delta_x, float delta_y);
float	calculate_move_distance(float speed, double delta_time);
float	clamp(float value, float min, float max);
void	get_direction_vector(float angle, double *dx, double *dy);
void	get_perpendicular_vector(float angle, float *dx, float *dy);

// Objects Manip
int		rotate_object(t_transform *transform, float rot_speed);

/*~~~~~~~~~~ RAYCASTER MATH SECTION ~~~~~~~~~~~ */
// Dual Path Algo
float	calculate_intercept(float player_pos, int flag);
float	calculate_step_primary(int flag, float tile_size);
float	calculate_step_secondary(float step_primary, float tan_a);

// Dda Algo
int		compute_initial_sides(t_dda *d);

// Raycaster
int		calculate_wall_height(t_ray *ray);

#endif
