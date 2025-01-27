/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:30:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/27 13:58:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/compute.h"

t_rayinfo	cast_ray_dda(t_data *data, float angle)
{
	t_rayinfo	ray;
	float		px;
	float		py;
	float		dir_x;
	float		dir_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	float		delta_x;
	float		delta_y;
	float		side_x;
	float		side_y;
	int			side;
	float		dist;

	px = data->player.x;
	py = data->player.y;
	dir_x = cosf(angle);
	dir_y = sinf(angle);
	map_x = (int)(px / TILE_SIZE);
	map_y = (int)(py / TILE_SIZE);
	step_x = 1;
	if (dir_x < 0.0f)
		step_x = -1;
	step_y = 1;
	if (dir_y < 0.0f)
		step_y = -1;
	if (fabsf(dir_x) < EPSILON)
		dir_x = EPSILON;
	if (fabsf(dir_y) < EPSILON)
		dir_y = EPSILON;
	delta_x = fabsf(1.0f / dir_x) * TILE_SIZE;
	delta_y = fabsf(1.0f / dir_y) * TILE_SIZE;
	/*
	** side_x / side_y = distance from (px, py) to the FIRST boundary in x / y.
	** We'll compute them below using the tile boundary approach.
	*/
	side_x = 0.0f;
	side_y = 0.0f;
	side = 0;

	/* --- Compute initial side_x --- */
	{
		float boundary_x;
		float dist_x;

		if (step_x > 0)
			boundary_x = (map_x + 1) * TILE_SIZE;
		else
			boundary_x = map_x * TILE_SIZE;
		dist_x = boundary_x - px;
		if (step_x < 0)
			dist_x = px - (map_x * TILE_SIZE);
		if (dir_x != 0.0f)
			side_x = fabsf(dist_x / dir_x);
	}

	/* --- Compute initial side_y --- */
	{
		float boundary_y;
		float dist_y;

		if (step_y > 0)
			boundary_y = (map_y + 1) * TILE_SIZE;
		else
			boundary_y = map_y * TILE_SIZE;
		dist_y = boundary_y - py;
		if (step_y < 0)
			dist_y = py - (map_y * TILE_SIZE);
		if (dir_y != 0.0f)
			side_y = fabsf(dist_y / dir_y);
	}

	/*
	** DDA loop: step in whichever direction is closer, check for walls or out-of-bounds
	*/
	while (1)
	{
		if (side_x < side_y)
		{
			side_x += delta_x;
			map_x += step_x;
			side = 0; /* vertical boundary stepped */
		}
		else
		{
			side_y += delta_y;
			map_y += step_y;
			side = 1; /* horizontal boundary stepped */
		}
		if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
			break ;
		if (g_map[map_y * MAP_WIDTH + map_x] == '1')
			break ;
	}
	/*
	** The distance traveled along the ray is side_x or side_y minus one increment:
	**   - If side=0 => we stepped last in x => the actual "full side_x" includes the final step.
	**     So the distance is side_x - delta_x.
	**   - If side=1 => we stepped last in y => side_y - delta_y.
	*/
	if (side == 0)
		dist = side_x - delta_x;
	else
		dist = side_y - delta_y;

	ray.dist = dist;
	ray.rx = px + (dist * dir_x);
	ray.ry = py + (dist * dir_y);
	ray.tile_x = map_x;
	ray.tile_y = map_y;
	/*
	** We'll store the side (0=vertical,1=horizontal) in map_index for now.
	** That way we don't alter your struct layout. Just read it in process_ray().
	*/
	ray.map_index = side;
	ray.color = 0xFFFFFF; /* We'll override color later. */
	return (ray);
}
