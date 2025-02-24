/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:58:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 08:46:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct s_line_vars
{
    t_coord dir;
    t_coord inc;
    t_coord cur;
	int		steps;	// how many steps to iterate
	int		i;
}	t_line_vars;

typedef struct s_rayinfo
{
    t_coord collision;
    t_coord tile;
    float dist;     // Distance to the collision
    int color;      // Color of the wall hit
    int map_index;  // Index in the map array
} t_rayinfo;

typedef enum e_wall_type
{
	WALL_NONE,       // Initial state
	WALL_VERTICAL,   // Wall hit by vertical ray
	WALL_HORIZONTAL  // Wall hit by horizontal ray
}	t_wall_type;


typedef struct s_ray
{
    float angle;              // Current ray angle
    t_rayinfo chosen;         // The chosen ray (closest intersection)
    float corrected_distance; // Distance corrected for fisheye
    int wall_height;          // Height of the wall slice
    float true_wall_height;          // Height of the wall slice
    t_wall_type current_wall; // Type of wall hit (vertical/horizontal)
    int line_offset;          // Y-coordinate offset to center the slice vertically
    int x_screen;             // X-coordinate on the screen
} t_ray;

typedef struct s_dda
{
    t_coord pos;
    t_coord dir;
    t_coord delta;
    t_coord side;
    t_coord map;
    t_coord step;
	int		sides;
	float	dist;
}	t_dda;

t_rayinfo   cast_ray_dda(t_data *data, float ray_angle);
int	        process_ray(t_data *data, t_ray *ray, float start_angle, int i, float fov);

#endif
