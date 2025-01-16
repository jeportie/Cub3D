/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:01:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/16 22:39:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib/minilibx/mlx.h"
#include "lib/libft/include/libft.h"

/*
    Window and square settings
*/
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define SQUARE_SIZE   5
#define MOVE_STEP     10

/*
    Keycodes (for MacOS):
    W: 13, A: 0, S: 1, D: 2, ESC: 53
*/
typedef struct s_data {
    void    *mlx;
    void    *win;
    int     square_x;
    int     square_y;
} t_data;

/*
    Draws a red square at the current position.
    Note: MLX's mlx_pixel_put is being used for simplicity.
*/
void    draw_square(t_data *data)
{
    int x;
    int y;

    y = data->square_y;
    while (y < data->square_y + SQUARE_SIZE)
    {
        x = data->square_x;
        while (x < data->square_x + SQUARE_SIZE)
        {
            mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000); // red color
            x++;
        }
        y++;
    }
}

/*
    Key hook function: moves the square with WASD and exits with ESC.
*/
int key_hook(int keycode, t_data *data)
{
    if (keycode == 50)  // ESC
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == 53)  // W key: move up
        data->square_y -= MOVE_STEP;
    else if (keycode == 54)   // S key: move down
        data->square_y += MOVE_STEP;
    else if (keycode == 55)   // A key: move left
        data->square_x -= MOVE_STEP;
    else if (keycode == 56)   // D key: move right
        data->square_x += MOVE_STEP;
    
    /* Clear the window and redraw the square at the new position */
    mlx_clear_window(data->mlx, data->win);
    draw_square(data);
    
    return (0);
}

/*
    Main entry point.
*/
int main(void)
{
    t_data data;

    /* Initialize MLX and create a new window */
    data.mlx = mlx_init();
    if (!data.mlx)
    {
        ft_dprintf(2, "Error: mlx_init() failed. Is an X server running?\n", 51);
        return (1);
    }
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Red Square");
    if (!data.win)
    {
        ft_dprintf(2, "Error: mlx_new_window() failed. Check your configuration.\n", 58);
        return (1);
    }

    /* Initialize square position at the center of the window */
    data.square_x = (WINDOW_WIDTH - SQUARE_SIZE) / 2;
    data.square_y = (WINDOW_HEIGHT - SQUARE_SIZE) / 2;

    /* Draw the initial square */
    draw_square(&data);

    /* Register the key hook to listen for keypress events */
    mlx_key_hook(data.win, key_hook, &data);

    /* Enter the MLX main loop */
    mlx_loop(data.mlx);

    return (0);
}

