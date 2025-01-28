/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_plane_raycast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:09:36 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/28 10:10:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/compute.h"

t_rayinfo cast_ray_dda_plane(t_data *data, double ray_dir_x, double ray_dir_y)
{
    t_rayinfo   rayinfo;
    t_dda       d;
    float       tile_size;

    tile_size = TILE_SIZE;
    rayinfo.rx = data->player.x;
    rayinfo.ry = data->player.y;
    rayinfo.dist = 0.0;
    rayinfo.color = 0;
    rayinfo.tile_x = 0;
    rayinfo.tile_y = 0;
    rayinfo.map_index = 0;

    /* Fill DDA structure with initial values */
    d.px = (float)data->player.x; /* pixel space */
    d.py = (float)data->player.y;
    d.dir_x = (float)ray_dir_x;
    d.dir_y = (float)ray_dir_y;
    d.map_x = (int)(d.px / tile_size);
    d.map_y = (int)(d.py / tile_size);

    if (d.dir_x < 0)
        d.step_x = -1;
    else
        d.step_x = 1;

    if (d.dir_y < 0)
        d.step_y = -1;
    else
        d.step_y = 1;

    /* Avoid zero division for deltaDistX, deltaDistY */
    if (d.dir_x == 0.0f)
        d.delta_x = 1e30;
    else
        d.delta_x = fabsf(1.0f / d.dir_x);

    if (d.dir_y == 0.0f)
        d.delta_y = 1e30;
    else
        d.delta_y = fabsf(1.0f / d.dir_y);

    compute_initial_sides(&d, data);

    d.side = 0;
    d.dist = 0.0f;
    /* DDA loop */
    while (1)
    {
        if (d.side_x < d.side_y)
        {
            d.side_x += d.delta_x;
            d.map_x += d.step_x;
            d.side = 0;
        }
        else
        {
            d.side_y += d.delta_y;
            d.map_y += d.step_y;
            d.side = 1;
        }
        if (d.map_x < 0 || d.map_y < 0
            || d.map_x >= MAP_WIDTH || d.map_y >= MAP_HEIGHT)
        {
            /* out of map bounds, break or set big distance */
            break ;
        }
        if (g_map[d.map_y * MAP_WIDTH + d.map_x] == '1')
        {
            break ;
        }
    }
    if (d.side == 0)
        d.dist = d.side_x - d.delta_x;
    else
        d.dist = d.side_y - d.delta_y;
    rayinfo.dist = d.dist;

    /*
     * Optionally compute the exact hit point in pixel space:
     * px + dir_x * dist => float
     * py + dir_y * dist => float
     */
    rayinfo.rx = d.px + d.dir_x * d.dist;
    rayinfo.ry = d.py + d.dir_y * d.dist;

    /*
     * tile_x / tile_y for reference
     */
    rayinfo.tile_x = d.map_x;
    rayinfo.tile_y = d.map_y;
    rayinfo.map_index = d.side;

    return (rayinfo);
}

