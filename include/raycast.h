/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:58:03 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/25 23:32:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct s_line_vars
{
	int		dx;		// delta_x: difference in x between start and end
	int		dy;		// delta_y: difference in y between start and end
	int		steps;	// number_of_steps: how many steps to iterate
	float	inc_x;	// increment_x: x increment per step
	float	inc_y;	// increment_y: y increment per step
	float	cur_x;	// current_x: current x coordinate while drawing the line
	float	cur_y;	// current_y: current y coordinate while drawing the line
	int		i;		// loop_index: iteration counter
}	t_line_vars;

typedef struct s_ray_cast_vars
{
	float	player_x;			// player_x_position: player’s x coordinate
	float	player_y;			// player_y_position: player’s y coordinate
	float	sin_a;				// sine_angle: sine of the ray angle
	float	cos_a;				// cosine_angle: cosine of the ray angle
	int		flag;				// flag_direction: for vertical (looking left) 
								// or horizontal (going up)
								// (nonzero if left/ up)
	float	intercept_primary;	// intercept_primary: first grid intercept on 
								// the primary axis
								// (x coordinate for vertical rays, y coordinate
								// for horizontal rays)
	float	dist_primary;		// distance_primary: distance along the primary
								// axis (xDist or yDist)
	float	tan_a;				// tangent_angle: tangent of the ray angle
	float	intercept_secondary;// intercept_secondary: first grid intercept on
								// the secondary axis
								// (y coordinate for vertical rays, x coordinate
								// for horizontal rays)
	float	step_primary;		// step_primary: grid step size in the primary 
								// direction (-TILE_SIZE or TILE_SIZE)
	float	step_secondary;		// step_secondary: grid step size in the 
								// secondary direction (computed using tan_a)
	float	ray_collision_x;	// ray_collision_x: final x coordinate where the
								// ray hits a wall
	float	ray_collision_y;	// ray_collision_y: final y coordinate where the
								// ray hits a wall
	int		loop_counter;		// loop_index: counter for looping along the ray
								// in the grid
	int		tile_x;				// tile_x_index: current map tile index in the x
								// direction
	int		tile_y;				// tile_y_index: current map tile index in the y
								// direction
	int		map_index;			// map_index: index in the global map array
								// (g_map)
	float	delta_x;			// delta_x: difference between collision x and
								// player x
	float	delta_y;			// delta_y: difference between collision y and
								// player y
	float	distance;			// distance: computed Euclidean distance from
								// the player to the collision point
}	t_ray_cast_vars;

typedef struct s_rayinfo
{
	float	rx;
	float	ry;
	float	dist;
	int		color;
}	t_rayinfo;

typedef enum e_wall_type
{
	WALL_NONE,       // Initial state
	WALL_VERTICAL,   // Wall hit by vertical ray
	WALL_HORIZONTAL  // Wall hit by horizontal ray
}	t_wall_type;

// Structure to store wall slice information
typedef struct s_wall_slice
{
    t_wall_type wall_type;  // Type of wall: vertical or horizontal
    int wall_height;        // Height of the wall slice
    int x_screen;           // X-coordinate on the screen where the slice is drawn
    int line_offset;        // Y-coordinate offset to center the slice vertically
} t_wall_slice;

typedef struct s_ray
{
    float angle;             // Current ray angle
    t_rayinfo vertical;     // Information from vertical ray casting
    t_rayinfo horizontal;   // Information from horizontal ray casting
    t_rayinfo chosen;       // The chosen ray (closest intersection)
    float corrected_distance;// Distance corrected for fisheye
    int wall_height;        // Height of the wall slice
    t_wall_type current_wall;// Type of wall hit (vertical/horizontal)
} t_ray;

typedef struct s_render_context
{
    int x_screen;           // X-coordinate on the screen
    int line_offset;        // Y-coordinate offset for centering
    int prev_wall;          // Previous wall type for continuity
    int old_wall_height;    // Previous wall height for continuity checks
} t_render_context;

t_rayinfo	cast_vertical_ray(t_data *data, float ray_angle);
t_rayinfo	cast_horizontal_ray(t_data *data, float ray_angle);

#endif
