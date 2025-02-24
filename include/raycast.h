/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:58:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct s_line_vars
{
	t_coord	dir;
	t_coord	inc;
	t_coord	cur;
	int		steps;
	int		i;
}	t_line_vars;

typedef struct s_rayinfo
{
	t_coord	collision;
	t_coord	tile;
	float	dist;
	int		color;
	int		map_index;
}			t_rayinfo;

typedef enum e_wall_type
{
	WALL_NONE,
	WALL_VERTICAL,
	WALL_HORIZONTAL
}	t_wall_type;

typedef struct s_ray
{
	float		angle;
	t_rayinfo	chosen;
	float		corrected_distance;
	int			wall_height;
	float		true_wall_height;
	t_wall_type	current_wall;
	int			line_offset;
	int			x_screen;
}			t_ray;

typedef struct s_dda
{
	t_coord	pos;
	t_coord	dir;
	t_coord	delta;
	t_coord	side;
	t_coord	map;
	t_coord	step;
	int		sides;
	float	dist;
}	t_dda;

int			process_ray(t_data *data, t_ray *ray, float start_angle, int i);

int			init_dda_struct(t_dda *d, t_data *data, float angle);
int			run_dda_loop(t_data *data, t_dda *d);
int			fill_rayinfo(t_dda *d, t_rayinfo *ray);
t_rayinfo	cast_ray_dda(t_data *data, double angle);

#endif
