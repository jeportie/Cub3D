/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:30:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 08:50:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include "../../include/compute.h"

void	init_dda_struct(t_dda *d, t_data *data, float angle)
{
	d->pos.x = data->player.pose.x;
	d->pos.y = data->player.pose.y;
	d->dir.x = cosf(angle);
	d->dir.y = sinf(angle);
	d->map.x = (int)(d->pos.x / TILE_SIZE);
	d->map.y = (int)(d->pos.y / TILE_SIZE);
	d->step.x = 1;
	if (d->dir.x < 0.0f)
		d->step.x = -1;
	d->step.y = 1;
	if (d->dir.y < 0.0f)
		d->step.y = -1;
	if (fabsf(d->dir.x) < EPSILON)
		d->dir.x = EPSILON;
	if (fabsf(d->dir.y) < EPSILON)
		d->dir.y = EPSILON;
	d->delta.x = fabsf(1.0f / d->dir.x) * TILE_SIZE;
	d->delta.y = fabsf(1.0f / d->dir.y) * TILE_SIZE;
	d->side.x = 0.0f;
	d->side.y = 0.0f;
	d->sides = 0;
	d->dist = 0.0f;
}

int	run_dda_loop(t_data *data, t_dda *d)
{
	while (1)
	{
		if (d->side.x < d->side.y)
		{
			d->side.x += d->delta.x;
			d->map.x += d->step.x;
			d->sides = 0;
		}
		else
		{
			d->side.y += d->delta.y;
			d->map.y += d->step.y;
			d->sides = 1;
		}
		if (d->map.x < 0 || d->map.x >= data->parse.map.width
			|| d->map.y < 0 || d->map.y >= data->parse.map.height)
		{
			break ;
		}
		if (data->map[(int)d->map.y * data->parse.map.width
				+ (int)d->map.x] == '1')
			break ;
	}
	return (0);
}

void	fill_rayinfo(t_dda *d, t_rayinfo *ray)
{
	float	dist;

	if (d->sides == 0)
		dist = d->side.x - d->delta.x;
	else
		dist = d->side.y - d->delta.y;
	ray->dist = dist;
	ray->collision.x = d->pos.x + (dist * d->dir.x);
	ray->collision.y = d->pos.y + (dist * d->dir.y);
	ray->tile.x = d->map.x;
	ray->tile.y = d->map.y;
	ray->map_index = d->sides;
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
	fill_rayinfo(&d, &ray);
	return (ray);
}
