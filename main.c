/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <you>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:01:31 by <you>             #+#    #+#             */
/*   Updated: 2025/01/20 15:45:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/**
 * Helper to convert timespec to double seconds.
 */
static double get_time_in_seconds(struct timespec ts)
{
    return ((double)ts.tv_sec + (double)ts.tv_nsec / 1e9);
}

/**
 * Put a pixel into our off-screen image buffer, not directly to the window.
 */
static void put_pixel_to_image(t_image *img, int x, int y, int color)
{
    if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
        return;
    char *dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

/**
 * Clear the entire image to the given color.
 */
static void clear_image(t_image *img, int color)
{
    for (int y = 0; y < WINDOW_HEIGHT; y++)
    {
        for (int x = 0; x < WINDOW_WIDTH; x++)
        {
            put_pixel_to_image(img, x, y, color);
        }
    }
}

/**
 * Draw the 8x8 map, centered in the window.
 */
static void draw_map(t_data *data)
{
    for (int row = 0; row < MAP_HEIGHT; row++)
    {
        for (int col = 0; col < MAP_WIDTH; col++)
        {
            char tile = g_map[row][col];
            int  base_color = (tile == '1') ? 0xFFFFFF : 0x000000;

            for (int py = 0; py < TILE_SIZE; py++)
            {
                for (int px = 0; px < TILE_SIZE; px++)
                {
                    int x = data->map_offset_x + col * TILE_SIZE + px;
                    int y = data->map_offset_y + row * TILE_SIZE + py;
                    int color = base_color;

                    // 1px border in gray
                    if (py == 0 || py == TILE_SIZE - 1 ||
                        px == 0 || px == TILE_SIZE - 1)
                    {
                        color = 0x666666;
                    }
                    put_pixel_to_image(&data->img, x, y, color);
                }
            }
        }
    }
}

/**
 * Draw the player as a small red square, plus a direction line.
 */
static void draw_player(t_data *data)
{
    const int SQUARE_SIZE = 10;

    // Center of the player (x, y)
    int center_x = (int)data->player.x;
    int center_y = (int)data->player.y;

    // 1) Draw the red square for the player
    int x_start = center_x - (SQUARE_SIZE / 2);
    int y_start = center_y - (SQUARE_SIZE / 2);

    for (int y = 0; y < SQUARE_SIZE; y++)
    {
        for (int x = 0; x < SQUARE_SIZE; x++)
        {
            int draw_x = x_start + x;
            int draw_y = y_start + y;
            put_pixel_to_image(&data->img, draw_x, draw_y, 0xFF0000); // Red
        }
    }

    // 2) Draw a short line in front of the player to visualize the direction
    // We'll say ~30 pixels long. We'll step from 0..30.
    int line_length = 30;
    for (int i = 0; i < line_length; i++)
    {
        int lx = center_x + (int)(data->player.dx * i);
        int ly = center_y + (int)(data->player.dy * i);
        put_pixel_to_image(&data->img, lx, ly, 0x00FF00); // Green direction line
    }
}

/**
 * Our per-frame update loop:
 *   - rotate if needed
 *   - move if needed
 *   - clamp angle between 0 and 2*PI
 *   - recalc dx, dy from angle
 *   - draw everything
 */
static int update(t_data *data)
{
    struct timespec current_time;
    double          delta;

    if (clock_gettime(CLOCK_MONOTONIC, &current_time) != 0)
    {
        perror("clock_gettime failed");
        return (1);
    }
    delta = get_time_in_seconds(current_time) - get_time_in_seconds(data->last_time);
    data->last_time = current_time;
    data->delta_accumulator += delta;

    // Print a small log about delta and accumulator
    printf("delta = %.6f, accumulator = %.6f\n", delta, data->delta_accumulator);
    fflush(stdout);

    // We'll aim for ~60 FPS
    const double time_step = 1.0 / 60.0;

    while (data->delta_accumulator >= time_step)
    {
        double move_distance = SPEED * time_step;  // translation per step

        // ROTATION
        // Multiply ROT_SPEED by 5 because you said “values are very small, multiply by 5”
        if (data->player.rot_left)
            data->player.angle -= ROT_SPEED * 5.0 * time_step;
        if (data->player.rot_right)
            data->player.angle += ROT_SPEED * 5.0 * time_step;

        // Keep angle in [0, 2π)
        if (data->player.angle < 0)
            data->player.angle += 2.0 * M_PI;
        else if (data->player.angle >= 2.0 * M_PI)
            data->player.angle -= 2.0 * M_PI;

        // Recalculate dx, dy from the angle
        data->player.dx = cos(data->player.angle);
        data->player.dy = sin(data->player.angle);

        // TRANSLATION
        // Now W means "move forward in the direction of angle"
        if (data->player.move_up)
        {
            data->player.x += data->player.dx * move_distance;
            data->player.y += data->player.dy * move_distance;
        }
        // S means "move backward"
        if (data->player.move_down)
        {
            data->player.x -= data->player.dx * move_distance;
            data->player.y -= data->player.dy * move_distance;
        }
        // A means "strafe left" (90° offset from angle)
        if (data->player.move_left)
        {
            data->player.x += cos(data->player.angle - M_PI_2) * move_distance;
            data->player.y += sin(data->player.angle - M_PI_2) * move_distance;
        }
        // D means "strafe right" (90° offset from angle)
        if (data->player.move_right)
        {
            data->player.x += cos(data->player.angle + M_PI_2) * move_distance;
            data->player.y += sin(data->player.angle + M_PI_2) * move_distance;
        }

        // Basic boundary checks so player stays in the window
        if (data->player.x < 0) data->player.x = 0;
        if (data->player.y < 0) data->player.y = 0;
        if (data->player.x > WINDOW_WIDTH) data->player.x = WINDOW_WIDTH;
        if (data->player.y > WINDOW_HEIGHT) data->player.y = WINDOW_HEIGHT;

        data->delta_accumulator -= time_step;
    }

    // Clear our off-screen image
    clear_image(&data->img, 0x000000);

    // Draw map and player
    draw_map(data);
    draw_player(data);

    // Show the final image
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);

    return (0);
}

/**
 * Handle key presses.
 *  - 65307 = ESC
 *  - 65361 = Left arrow
 *  - 65363 = Right arrow
 *  - 119 (W), 115 (S), 97 (A), 100 (D)
 */
static int key_press(int keycode, t_data *data)
{
    printf("Key Pressed: keycode = %d\n", keycode);
    fflush(stdout);

    // ESC
    if (keycode == 65307)
    {
        printf("ESC pressed. Exiting.\n");
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == 65361) // Left arrow
        data->player.rot_left = true;
    else if (keycode == 65363) // Right arrow
        data->player.rot_right = true;
    else if (keycode == 119) // W
        data->player.move_up = true;
    else if (keycode == 115) // S
        data->player.move_down = true;
    else if (keycode == 97)  // A
        data->player.move_left = true;
    else if (keycode == 100) // D
        data->player.move_right = true;

    return (0);
}

/**
 * Handle key releases.
 */
static int key_release(int keycode, t_data *data)
{
    printf("Key Released: keycode = %d\n", keycode);
    fflush(stdout);

    if (keycode == 65361) // Left arrow
        data->player.rot_left = false;
    else if (keycode == 65363) // Right arrow
        data->player.rot_right = false;
    else if (keycode == 119) // W
        data->player.move_up = false;
    else if (keycode == 115) // S
        data->player.move_down = false;
    else if (keycode == 97)  // A
        data->player.move_left = false;
    else if (keycode == 100) // D
        data->player.move_right = false;

    return (0);
}

/**
 * Find 'P' in g_map to set the player's initial (x, y) (with offset).
 */
static void init_player_position(t_data *data)
{
    for (int row = 0; row < MAP_HEIGHT; row++)
    {
        for (int col = 0; col < MAP_WIDTH; col++)
        {
            if (g_map[row][col] == 'P')
            {
                data->player.x = data->map_offset_x + col * TILE_SIZE + (TILE_SIZE / 2);
                data->player.y = data->map_offset_y + row * TILE_SIZE + (TILE_SIZE / 2);

                // Initialize angle to 0 for now. dx = cos(0)=1, dy=sin(0)=0
                data->player.angle = 0.0;
                data->player.dx = cos(data->player.angle);
                data->player.dy = sin(data->player.angle);
                return;
            }
        }
    }
}

/**
 * Print the map layout for debugging.
 */
static void print_map(void)
{
    printf("Map layout (0=floor, 1=wall, P=player):\n");
    for (int row = 0; row < MAP_HEIGHT; row++)
    {
        for (int col = 0; col < MAP_WIDTH; col++)
            printf("%c ", g_map[row][col]);
        printf("\n");
    }
    printf("\n");
}

/**
 * Center the map in the window.
 */
static void compute_map_offset(t_data *data)
{
    int map_pixel_width  = MAP_WIDTH  * TILE_SIZE;
    int map_pixel_height = MAP_HEIGHT * TILE_SIZE;

    data->map_offset_x = (WINDOW_WIDTH  - map_pixel_width)  / 2;
    data->map_offset_y = (WINDOW_HEIGHT - map_pixel_height) / 2;

    if (data->map_offset_x < 0) data->map_offset_x = 0;
    if (data->map_offset_y < 0) data->map_offset_y = 0;
}

/**
 * Initialize an image buffer (t_image) for drawing.
 */
static void init_image(t_data *data)
{
    data->img.img_ptr = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!data->img.img_ptr)
    {
        ft_dprintf(2, "Error: mlx_new_image() failed.\n");
        exit(1);
    }
    data->img.addr = mlx_get_data_addr(data->img.img_ptr,
                                       &data->img.bpp,
                                       &data->img.line_len,
                                       &data->img.endian);
    if (!data->img.addr)
    {
        ft_dprintf(2, "Error: mlx_get_data_addr() failed.\n");
        exit(1);
    }
}

/**
 * Main entry point.
 */
int main(void)
{
    t_data data;

    ft_memset(&data, 0, sizeof(t_data));

    data.mlx = mlx_init();
    if (!data.mlx)
    {
        ft_dprintf(2, "Error: mlx_init() failed.\n");
        return (1);
    }
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d with rotation");
    if (!data.win)
    {
        ft_dprintf(2, "Error: mlx_new_window() failed.\n");
        return (1);
    }

    printf("MLX initialized and window created.\n");

    // Initialize image buffer
    init_image(&data);

    // Center the map
    compute_map_offset(&data);

    // Place player from 'P'
    init_player_position(&data);

    // Print map to console
    print_map();

    // Get the initial time
    if (clock_gettime(CLOCK_MONOTONIC, &data.last_time) != 0)
    {
        perror("clock_gettime failed");
        return (1);
    }

    // Register hooks
    mlx_hook(data.win, 2, 1L << 0, key_press, &data);
    mlx_hook(data.win, 3, 1L << 1, key_release, &data);

    // Continuous render loop
    mlx_loop_hook(data.mlx, update, &data);

    printf("Entering MLX event loop.\n");
    fflush(stdout);

    mlx_loop(data.mlx);
    return (0);
}

