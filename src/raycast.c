/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:04:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 21:10:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/engine.h"   // for put_pixel_to_image, etc.
#include "../include/player.h"

/*
** We can define a small structure here to hold the intersection 
** info (rx, ry, dist).
*/
typedef struct s_rayinfo
{
    float rx;
    float ry;
    float dist;
}   t_rayinfo;

/*
** A helper function to draw a simple line from (x0,y0) to (x1,y1).
*/
static void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float incX = (float)dx / (float)steps;
    float incY = (float)dy / (float)steps;

    float curX = x0;
    float curY = y0;
    for (int i = 0; i <= steps; i++)
    {
        put_pixel_to_image(&data->img, (int)curX, (int)curY, color);
        curX += incX;
        curY += incY;
    }
}

/*
** Cast a vertical intersection ray for angle 'rayAngle'. 
**   - returns (rx, ry, dist) in *window coords*, 
**   - or a large dist if angle is near vertical, etc.
*/
static t_rayinfo castVerticalRay(t_data *data, float rayAngle)
{
    t_rayinfo result;

    // Convert player's (px,py) from window => map coords
    float screenPX = data->player.x;
    float screenPY = data->player.y;
    float mapPX = screenPX - data->map_offset_x;
    float mapPY = screenPY - data->map_offset_y;

    float cosA = cosf(rayAngle);
    float sinA = sinf(rayAngle);

    // If cosA ~ 0 => purely vertical => set a big distance => won't be chosen
    if (fabsf(cosA) < 0.0001f)
    {
        result.rx = screenPX;
        result.ry = screenPY;
        result.dist = 999999.0f;
        return result;
    }

    // Are we looking left or right?
    int lookingLeft = (cosA < 0);

    // Next vertical boundary in map coords
    float xVert;
    if (lookingLeft)
        xVert = floorf(mapPX / 64.0f) * 64.0f;
    else
        xVert = floorf(mapPX / 64.0f) * 64.0f + 64.0f;

    float distX = xVert - mapPX;
    float tanA = sinA / cosA;
    float yVert = mapPY + distX * tanA;

    float xStep = lookingLeft ? -64.0f : 64.0f;
    float yStep = xStep * tanA;

    float rx = xVert;
    float ry = yVert;

    // Step tile by tile
    for (int stepCount = 0; stepCount < 64; stepCount++)
    {
        int tileX = (int)(rx / 64.0f);
        int tileY = (int)(ry / 64.0f);

        if (tileX < 0 || tileX >= MAP_WIDTH ||
            tileY < 0 || tileY >= MAP_HEIGHT)
            break; // out of map

        int mapIndex = tileY * MAP_WIDTH + tileX;
        if (g_map[mapIndex] == '1')
            break; // hit wall

        rx += xStep;
        ry += yStep;
    }

    // Convert intersection => window coords
    float screenRX = rx + data->map_offset_x;
    float screenRY = ry + data->map_offset_y;

    // Distance
    float dx = screenRX - screenPX;
    float dy = screenRY - screenPY;
    float dist = sqrtf(dx*dx + dy*dy);

    result.rx   = screenRX;
    result.ry   = screenRY;
    result.dist = dist;
    return result;
}

/*
** Cast a horizontal intersection ray for angle 'rayAngle'.
**   - returns (rx, ry, dist) in window coords
**   - or a big dist if angle is near horizontal
*/
static t_rayinfo castHorizontalRay(t_data *data, float rayAngle)
{
    t_rayinfo result;

    // Convert from window => map coords
    float screenPX = data->player.x;
    float screenPY = data->player.y;
    float mapPX    = screenPX - data->map_offset_x;
    float mapPY    = screenPY - data->map_offset_y;

    float sinA = sinf(rayAngle);
//    float cosA = cosf(rayAngle);

    // If sinA ~ 0 => purely horizontal => we do a large dist
    if (fabsf(sinA) < 0.0001f)
    {
        result.rx   = screenPX;
        result.ry   = screenPY;
        result.dist = 999999.0f;
        return result;
    }

    float aTan = -1.0f / tanf(rayAngle);

    // Instead of (angle>π => up), we do "if sinA < 0 => up"
    int goingUp = (sinA < 0);

    float ry; 
    if (goingUp)
        ry = floorf(mapPY / 64.0f) * 64.0f; // next boundary above
    else
        ry = floorf(mapPY / 64.0f) * 64.0f + 64.0f;

    float distY = ry - mapPY;
    float rx = mapPX + distY * aTan;

    float yOffset = goingUp ? -64.0f : 64.0f;
    float xOffset = -yOffset * aTan;

    // step
    for (int dof = 0; dof < 64; dof++)
    {
        int tileX = (int)(rx / 64.0f);
        int tileY = (int)(ry / 64.0f);

        if (tileX < 0 || tileX >= MAP_WIDTH ||
            tileY < 0 || tileY >= MAP_HEIGHT)
            break;
        int mapIndex = tileY * MAP_WIDTH + tileX;
        if (g_map[mapIndex] == '1')
            break;
        rx += xOffset;
        ry += yOffset;
    }

    // Convert => screen coords
    float screenRX = rx + data->map_offset_x;
    float screenRY = ry + data->map_offset_y;

    // Distance
    float dx = screenRX - screenPX;
    float dy = screenRY - screenPY;
    float dist = sqrtf(dx*dx + dy*dy);

    result.rx   = screenRX;
    result.ry   = screenRY;
    result.dist = dist;
    return result;
}

/*
** Public function: cast exactly ONE ray using player's angle,
** pick the closer intersection among vertical/horizontal,
** and draw it in green.
*/
int draw_rays(t_data *data)
{
    float rayAngle = data->player.angle;

    // Cast vertical
    t_rayinfo vRay = castVerticalRay(data, rayAngle);
    // Cast horizontal
    t_rayinfo hRay = castHorizontalRay(data, rayAngle);

    // pick whichever is closer
    t_rayinfo chosen;
    if (vRay.dist < hRay.dist)
        chosen = vRay;
    else
        chosen = hRay;

    // draw a line from player's position to the chosen intersection
    draw_line(data,
              (int)data->player.x,
              (int)data->player.y,
              (int)chosen.rx,
              (int)chosen.ry,
              0x00FF00);

    return (0);
}

