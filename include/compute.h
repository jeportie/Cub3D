/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:23:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/07 14:59:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H

# include "cub3d.h"
# include "raycast.h"

//raycaster
float	normalize_angle(float angle);
float	correct_fisheye(float player_angle, float ray_angle, float distance);
int		calculate_wall_height(t_ray *ray);
float	compute_wall_height(float distance);
float	get_safe_cos(float angle);
float	get_safe_sin(float angle);
float	calculate_intercept(float player_pos, int flag);
float	calculate_tan_a(float angle);
float	calculate_step_primary(int flag, float tile_size);
float	calculate_step_secondary(float step_primary, float tan_a);

//dda algo
float	compute_first_boundary_x(t_dda *d);
float	compute_first_boundary_y(t_dda *d);
void	compute_initial_sides(t_dda *d, t_data *data);

//player
float	calculate_distance(float delta_x, float delta_y);
void	get_direction_vector(float angle, double *dx, double *dy);
void	get_perpendicular_vector(float angle, float *dx, float *dy);
float	calculate_move_distance(float speed, double delta_time);
float	clamp(float value, float min, float max);

#endif
