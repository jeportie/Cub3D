/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:43:52 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 13:35:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/raycast.h"
#include "../include/minimap.h" // for g_map, MAP_WIDTH, MAP_HEIGHT, etc.
#include "../include/engine.h"   // for put_pixel_to_image
#include "../include/player.h"
#include "../include/error.h"

/**
 * We'll do a small helper to draw a line from (x0,y0) to (x1,y1)
 * so we can visualize the ray on the minimap.
 */
static void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    // Very naive line-draw (similar to DDA)
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float incX = (float)dx / (float)steps;
    float incY = (float)dy / (float)steps;

    float currentX = x0;
    float currentY = y0;
    for (int i = 0; i <= steps; i++)
    {
        put_pixel_to_image(&data->img, (int)currentX, (int)currentY, color);
        currentX += incX;
        currentY += incY;
    }
}

/**
 * This function is your original "draw_rays()" from next_step.c, 
 * but with renamed variables for clarity and small fixes:
 *   - We reference data->player.x as px, data->player.y as py
 *   - We use 'g_map[]' for the map
 *   - We fix syntax: "0,0001" -> 0.0001f, dof++ instead of dof += 1 ...
 *   - We only check vertical lines, but the code says "check horizontal"—we keep it as is
 *   - We draw the final intersection as a line on the minimap
 */
int draw_rays(t_data *data)
{
    // We'll treat px, py as player's position in float
    float px = data->player.x;
    float py = data->player.y;

    // For now, let's assume we're casting RAYS = 1 or multiple 
    // (Your define says #define RAYS 1, so we do 1 iteration).
    int rayIdx = 0;
    while (rayIdx < RAYS)
    {
        // Original code's variables renamed:
      //  int   tileX;         // was mx
     //   int   tileY;         // was my
    //    int   mapIndex;      // was mp
        int   depthOfField;  // was dof
        float rayX;          // was rx
        float rayY;          // was ry
        float rayAngle;      // was ra
        float xOffset;       // was xo
        float yOffset;       // was yo

        // For demonstration, let's set rayAngle to data->player.angle 
        // (You could do rayAngle = data->player.angle + someOffset if multiple rays)
        rayAngle = data->player.angle;

        depthOfField = 0;
        float negTan = -1.0f / tan(rayAngle);

        // 1) If angle > M_PI, do something
        if (rayAngle > M_PI)
        {
            rayY = (((int)py >> 6) << 6);// - 0.0001f;  
            rayY -= 0.0f;
            rayX = (py - rayY) * negTan + px;
            yOffset = -64;
            xOffset = -yOffset * negTan;
        }
        // 2) If angle < M_PI, do something else
        else if (rayAngle < M_PI)
        {
            rayY = (((int)py >> 6) << 6) + 64;  
            rayX = (py - rayY) * negTan + px;
            yOffset = 64;
            xOffset = -yOffset * negTan;
        }
        // 3) if angle = 0 or angle = M_PI 
        else
        {
            rayX = px;
            rayY = py;
            depthOfField = 8; // stops the while below
        }

        // 4) Move step by step until we hit a wall or depthOfField >= 8
        while (depthOfField < 8)
		{
			int tileX = (int)(rayX) >> 6;
			int tileY = (int)(rayY) >> 6;
			if (tileX < 0 || tileX >= MAP_WIDTH || tileY < 0 || tileY >= MAP_HEIGHT)
			{
				depthOfField = 8;
			}
			else
			{
				int mapIndex = tileY * MAP_WIDTH + tileX;
				if (g_map[mapIndex] == '1')
					depthOfField = 8;
				else
				{
					rayX += xOffset;
					rayY += yOffset;
					depthOfField++;
				}
			}
		}

        // Now we have a rayX, rayY intersection
        // Let's draw a line from player's position to (rayX, rayY)
        draw_line(data, (int)px, (int)py, (int)rayX, (int)rayY, 0x00FF00);

        // If you had multiple rays, you'd do rayAngle += small increment
        // but for now we only do 1
        rayIdx++;
    }
    return (0);
}

