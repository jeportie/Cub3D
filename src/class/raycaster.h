/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:55:23 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 23:13:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "graphic_engine.h"

typedef struct s_game_api	t_game_api;
typedef struct s_game	t_game;

typedef struct s_raycaster_api
{
	t_game_api	base;
}				t_raycaster_api;

extern const t_raycaster_api	g_raycaster_methods;

typedef struct s_raycaster
{
	t_game			base;

	const t_raycaster_api	*methods;
}				t_raycaster;

typedef struct s_line_vars
{
	int		dx;		// difference in x between start and end
	int		dy;		// difference in y between start and end
	int		steps;	// how many steps to iterate
	float	inc_x;	// x increment per step
	float	inc_y;	// y increment per step
	float	cur_x;	// x coordinate while drawing the line
	float	cur_y;	// y coordinate while drawing the line
	int		i;
}	t_line_vars;

typedef struct s_rayinfo
{
    float rx;       // Final x-coordinate of collision
    float ry;       // Final y-coordinate of collision
    float dist;     // Distance to the collision
    int color;      // Color of the wall hit
    int tile_x;     // Tile index in the x-direction
    int tile_y;     // Tile index in the y-direction
    int map_index;  // Index in the map array
} t_rayinfo;

typedef struct s_ray_cast
{
    float player_x;       // Player's x position
    float player_y;       // Player's y position
    float sin_a;          // Sine of the ray angle
    float cos_a;          // Cosine of the ray angle
    int flag;             // Direction flag (up/down or left/right)
    float tan_a;          // Tangent of the ray angle
    float step_x;         // Step size in the x direction
    float step_y;         // Step size in the y direction
    float intercept_x;    // Initial x-intercept
    float intercept_y;    // Initial y-intercept
    t_rayinfo result;     // Final collision result
} t_ray_cast;

typedef enum e_wall_type
{
	WALL_NONE,       // Initial state
	WALL_VERTICAL,   // Wall hit by vertical ray
	WALL_HORIZONTAL  // Wall hit by horizontal ray
}	t_wall_type;

typedef struct s_ray
{
    float angle;              // Current ray angle
    t_rayinfo vertical;       // Information from vertical ray casting
    t_rayinfo horizontal;     // Information from horizontal ray casting
    t_rayinfo chosen;         // The chosen ray (closest intersection)
    float corrected_distance; // Distance corrected for fisheye
    int wall_height;          // Height of the wall slice
    float true_wall_height;          // Height of the wall slice
    t_wall_type current_wall; // Type of wall hit (vertical/horizontal)
    int line_offset;          // Y-coordinate offset to center the slice vertically
    int x_screen;             // X-coordinate on the screen
} t_ray;

typedef struct s_rndr_ctx
{
    int x_screen;           // X-coordinate on the screen
    int line_offset;        // Y-coordinate offset for centering
    int prev_wall;          // Previous wall type for continuity
    int old_wall_height;    // Previous wall height for continuity checks
    int prev_tile_x;
    int prev_tile_y; 
} t_rndr_ctx;

typedef struct s_dda
{
	float	px;
	float	py;
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	float	delta_x;
	float	delta_y;
	float	side_x;
	float	side_y;
	int		side;
	float	dist;
}	t_dda;


/* ~~~~~~~~~~~ CORE ENGINE METHODS ~~~~~~~~~~~~~*/
t_raycaster	*create_raycaster(void);
int			init_raycaster(t_raycaster *raycaster);
int			run_raycaster(t_raycaster *raycaster);
int			destroy_raycaster(t_raycaster *raycaster);


t_rayinfo	cast_vertical_ray(t_data *data, float ray_angle);
t_rayinfo	cast_horizontal_ray(t_data *data, float ray_angle);
t_rayinfo   cast_ray_dda(t_data *data, float ray_angle);

#endif
