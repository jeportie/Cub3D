/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:30:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 17:20:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/compute.h"

void	init_dda_struct(t_dda *d, t_data *data, float angle)
{
	d->px = data->player.x;
	d->py = data->player.y;
	d->dir_x = cosf(angle);
	d->dir_y = sinf(angle);
	d->map_x = (int)(d->px / TILE_SIZE);
	d->map_y = (int)(d->py / TILE_SIZE);
	d->step_x = 1;
	if (d->dir_x < 0.0f)
		d->step_x = -1;
	d->step_y = 1;
	if (d->dir_y < 0.0f)
		d->step_y = -1;
	if (fabsf(d->dir_x) < EPSILON)
		d->dir_x = EPSILON;
	if (fabsf(d->dir_y) < EPSILON)
		d->dir_y = EPSILON;
	d->delta_x = fabsf(1.0f / d->dir_x) * TILE_SIZE;
	d->delta_y = fabsf(1.0f / d->dir_y) * TILE_SIZE;
	d->side_x = 0.0f;
	d->side_y = 0.0f;
	d->side = 0;
	d->dist = 0.0f;
}

int	run_dda_loop(t_data *data, t_dda *d)
{
	int	out_of_bounds;

	out_of_bounds = 0;
	while (1)
	{
		if (d->side_x < d->side_y)
		{
			d->side_x += d->delta_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_y += d->delta_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->map_x < 0 || d->map_x >= data->parse.map.width
			|| d->map_y < 0 || d->map_y >= data->parse.map.height)
		{
			out_of_bounds = 1;
			break ;
		}
		if (data->map[d->map_y * data->parse.map.width + d->map_x] == '1')
			break ;
	}
	return (out_of_bounds);
}

void	fill_rayinfo(t_dda *d, t_data *data, t_rayinfo *ray)
{
	float	dist;

	if (d->side == 0)
		dist = d->side_x - d->delta_x;
	else
		dist = d->side_y - d->delta_y;
	ray->dist = dist;
	ray->rx = d->px + (dist * d->dir_x);
	ray->ry = d->py + (dist * d->dir_y);
	ray->tile_x = d->map_x;
	ray->tile_y = d->map_y;
	ray->map_index = d->side;
	(void)data;
}

t_rayinfo	cast_ray_dda(t_data *data, float angle)
{
	t_rayinfo	ray;
	t_dda		d;

	ft_bzero(&ray, sizeof(t_rayinfo));
	ft_bzero(&d, sizeof(t_dda));
	init_dda_struct(&d, data, angle);
	compute_initial_sides(&d, data);
	run_dda_loop(data, &d);
	fill_rayinfo(&d, data, &ray);
	return (ray);
}
