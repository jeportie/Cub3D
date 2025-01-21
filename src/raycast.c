/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:27:34 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 22:26:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/engine.h"
#include "../include/player.h"

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

static t_rayinfo castVerticalRay(t_data *data, float angle)
{
    t_rayinfo result;

    float px = data->player.x;
    float py = data->player.y;

    float cosA = cosf(angle);
    float sinA = sinf(angle);

    if (fabsf(cosA) < 0.0001f)
    {
        // big dist => won't pick
        result.rx = px;
        result.ry = py;
        result.dist = 999999.0f;
        return result;
    }

    // left or right
    int lookingLeft = (cosA < 0);

    float xVert;
    if (lookingLeft)
        xVert = floorf(px / 64.0f) * 64.0f;
    else
        xVert = floorf(px / 64.0f) * 64.0f + 64.0f;

    float distX = xVert - px;
    float tanA = sinA / cosA;
    float yVert = py + distX * tanA;

    float xStep = lookingLeft ? -64.0f : 64.0f;
    float yStep = xStep * tanA;

    float rx = xVert;
    float ry = yVert;

    for (int i = 0; i < 64; i++)
    {
        int tileX = (int)(rx / 64.0f);
        int tileY = (int)(ry / 64.0f);

        if (tileX < 0 || tileX >= MAP_WIDTH ||
            tileY < 0 || tileY >= MAP_HEIGHT)
            break;
        int index = tileY * MAP_WIDTH + tileX;
        if (g_map[index] == '1')
            break;
        rx += xStep;
        ry += yStep;
    }

    float dx = rx - px;
    float dy = ry - py;
    float dist = sqrtf(dx*dx + dy*dy);

    result.rx   = rx;
    result.ry   = ry;
    result.dist = dist;
    return result;
}

// Cast horizontal
static t_rayinfo castHorizontalRay(t_data *data, float angle)
{
    t_rayinfo result;

    float px = data->player.x;
    float py = data->player.y;

    float sinA = sinf(angle);

    if (fabsf(sinA) < 0.0001f)
    {
        result.rx = px;
        result.ry = py;
        result.dist = 999999.0f;
        return result;
    }

    float aTan = -1.0f / tanf(angle);
    int goingUp = (sinA < 0);

    float ry;
    if (goingUp)
        ry = floorf(py / 64.0f) * 64.0f;
    else
        ry = floorf(py / 64.0f) * 64.0f + 64.0f;

    float distY = ry - py;
    float rx = px + distY * aTan;

    float yOffset = goingUp ? -64.0f : 64.0f;
    float xOffset = -yOffset * aTan;

    for (int i = 0; i < 64; i++)
    {
        int tileX = (int)(rx / 64.0f);
        int tileY = (int)(ry / 64.0f);

        if (tileX < 0 || tileX >= MAP_WIDTH ||
            tileY < 0 || tileY >= MAP_HEIGHT)
            break;
        int index = tileY * MAP_WIDTH + tileX;
        if (g_map[index] == '1')
            break;
        rx += xOffset;
        ry += yOffset;
    }

    float dx = rx - px;
    float dy = ry - py;
    float dist = sqrtf(dx*dx + dy*dy);

    result.rx   = rx;
    result.ry   = ry;
    result.dist = dist;
    return result;
}

/*
** Public function: just cast one ray from player's angle,
** pick whichever intersection is closer, draw it in green.
*/
int draw_rays(t_data *data)
{
    float rayAngle = data->player.angle;

    t_rayinfo vert = castVerticalRay(data, rayAngle);
    t_rayinfo hori = castHorizontalRay(data, rayAngle);

    t_rayinfo chosen = (vert.dist < hori.dist) ? vert : hori;

    // draw from (player.x, player.y) => chosen.(rx,ry) in local coords
    // the map is top-left => so these coords directly match the window
    draw_line(data, 
        (int)data->player.x,
        (int)data->player.y,
        (int)chosen.rx,
        (int)chosen.ry,
        0x00FF00
    );

    return 0;
}
