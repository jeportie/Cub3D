/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plane_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:12:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/28 10:14:04 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"
#include "../../include/raycast.h"
#include "../../include/cub3d.h"
#include "../../include/engine.h"
#include "../../include/colors.h"

/*
 * This is similar to Lode's approach except we use RAYS as "screen columns".
 * You could also use THREE_D_WIDTH if you want 1:1 pixel columns.
 */

static int calculate_plane_wall_height(float distance)
{
    float result;

    if (distance < 0.0001f)
        distance = 0.0001f;
    /* A typical Lode approach might do: lineHeight = (int)(THREE_D_HEIGHT / distance).
     * But to keep consistent with your existing approach, you can do something like:
     *   result = (TILE_SIZE / distance) * (THREE_D_WIDTH / 2) / tanf(FOV / 2).
     * We'll do a simpler direct approach for demonstration.
     */
    result = (float)THREE_D_HEIGHT / distance;
    if (result > THREE_D_HEIGHT)
        result = THREE_D_HEIGHT;
    return ((int)result);
}

void render_plane_mode(t_data *data, t_image *img)
{
    int     x;
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
    t_rayinfo rayinfo;
    int     wall_height;
    int     line_offset;
    int     y;
    int     color;

    draw_background(img);
    x = 0;
    while (x < RAYS)
    {
        camera_x = 2.0 * (double)x / (double)RAYS - 1.0;
        ray_dir_x = data->player.dx + data->player.plane_x * camera_x;
        ray_dir_y = data->player.dy + data->player.plane_y * camera_x;
        rayinfo = cast_ray_dda_plane(data, ray_dir_x, ray_dir_y);

        wall_height = calculate_plane_wall_height(rayinfo.dist);
        line_offset = (THREE_D_HEIGHT / 2) - (wall_height / 2);
        color = RED;
        if (rayinfo.map_index == 1)
            color = GOLD; /* vertical/horizontal shading, optional */

        y = 0;
        while (y < wall_height)
        {
            if (y + line_offset >= 0 && y + line_offset < THREE_D_HEIGHT)
                put_pixel_to_image(img, THREE_D_X + x, y + line_offset, color);
            y++;
        }
        x++;
    }
}

