/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:45:15 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/05 20:30:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/engine.h"
#include "../include/compute.h"

int	get_pixel_from_texture(t_image *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}

int texture_transform(t_image *texture, t_ray *ray, t_image *img)
{
    int texWidth = TILE_SIZE;   // Texture width (adjust if needed)
    int texHeight = TILE_SIZE;  // Texture height (adjust if needed)
    float ty_step;            // How many texture pixels per screen pixel.
    float texPos;             // Starting texture Y coordinate.
    int drawStart;
    int drawEnd;
    int y;
    int texture_x;
    int color;

    // Detect if we are in plane mode by comparing wall height:
    float planeWallHeight = calculate_plane_wall_height(ray->chosen.dist);
    bool plane_mode = fabs((float)ray->wall_height - planeWallHeight) < 0.001f;

    if (plane_mode)
    {
        // In plane mode, use the pre-computed tile offset.
        if (ray->current_wall == WALL_VERTICAL)
            texture_x = ray->chosen.tile_x;
        else
            texture_x = ray->chosen.tile_y;
    }
    else
    {
        // Angle mode: use raw hit coordinate modulo texture width.
        if (ray->current_wall == WALL_VERTICAL)
            texture_x = ((int)ray->chosen.ry) % texWidth;
        else
            texture_x = ((int)ray->chosen.rx) % texWidth;
    }
    if (texture_x < 0)
        texture_x = 0;

    // Compute the vertical texture step
    ty_step = (float)texHeight / ray->wall_height;

    if (ray->wall_height > THREE_D_HEIGHT)
    {
        drawStart = 0;
        drawEnd = THREE_D_HEIGHT;
        // Calculate how many pixels of the wall are off-screen at the top.
        float ty_off = (ray->wall_height - THREE_D_HEIGHT) / 2.0f;
        texPos = ty_off * ty_step;
        printf("DEBUG: wall_height=%d, ty_step=%f, ty_off=%f, texPos=%f\n",
            ray->wall_height, ty_step, ty_off, texPos);
    }
    else
    {
        drawStart = ray->line_offset;
        drawEnd = ray->line_offset + ray->wall_height;
        if (drawStart < 0)
        {
            texPos = -drawStart * ty_step;
            drawStart = 0;
        }
        else
        {
            texPos = 0.0f;
        }
        if (drawEnd > THREE_D_HEIGHT)
            drawEnd = THREE_D_HEIGHT;
    }

    y = drawStart;
    while (y < drawEnd)
    {
        int texture_y = (int)texPos;
        if (texture_y < 0)
            texture_y = 0;
        if (texture_y >= texHeight)
            texture_y = texHeight - 1;
        texPos += ty_step;
        color = get_pixel_from_texture(texture, texture_x, texture_y);
        put_pixel_to_image(img, ray->x_screen, y, color);
        y++;
    }
    return (0);
}
