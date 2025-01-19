/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:01:31 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/17 21:44:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	draw_square(t_data *data)
{
	int	x;
	int	y;

	y = data->square_y;
	while (y < data->square_y + SQUARE_SIZE)
	{
		x = data->square_x;
		while (x < data->square_x + SQUARE_SIZE)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

double	get_time_in_seconds(struct timespec ts)
{
	return ((double)ts.tv_sec + (double)ts.tv_nsec / 1e9);
}

int	update(t_data *data)
{
	struct timespec	current_time;
	double			delta;
	double			move_distance;
	int				dx = 0;
	int				dy = 0;
	static int		update_count = 0;

	if (clock_gettime(CLOCK_MONOTONIC, &current_time) != 0)
	{
		perror("clock_gettime failed");
		exit(EXIT_FAILURE);
	}
	delta = get_time_in_seconds(current_time) - get_time_in_seconds(data->last_time);
	data->last_time = current_time;

	data->delta_accumulator += delta;

	const double time_step = 1.0 / 60.0;  /* ~60 FPS update step */

	while (data->delta_accumulator >= time_step)
	{
		move_distance = SPEED * time_step; // pixels to move this time step
		if (data->key_w)
			dy -= (int)(move_distance);
		if (data->key_s)
			dy += (int)(move_distance);
		if (data->key_a)
			dx -= (int)(move_distance);
		if (data->key_d)
			dx += (int)(move_distance);
		if (dx != 0 || dy != 0)
		{
			data->square_x += dx;
			data->square_y += dy;
			if (data->square_x < 0)
				data->square_x = 0;
			if (data->square_y < 0)
				data->square_y = 0;
			if (data->square_x + SQUARE_SIZE > WINDOW_WIDTH)
				data->square_x = WINDOW_WIDTH - SQUARE_SIZE;
			if (data->square_y + SQUARE_SIZE > WINDOW_HEIGHT)
				data->square_y = WINDOW_HEIGHT - SQUARE_SIZE;
			printf("Moved to (%d, %d)\n", data->square_x, data->square_y);
			mlx_clear_window(data->mlx, data->win);
			draw_square(data);
		}
		data->delta_accumulator -= time_step;
	}
	update_count++;
	if (update_count % 3600 == 0)  /* Print every ~3 seconds if at 60 FPS */
	{
		printf("Update tick: delta=%.6f, accumulator=%.6f\n", delta, data->delta_accumulator);
	}
	return (0);
}

int key_press(int keycode, t_data *data)
{
    printf("Key Pressed: keycode = %d\n", keycode);
    fflush(stdout);
    if (keycode == 65307)  /* ESC key */
    {
        printf("ESC pressed. Exiting.\n");
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == 119)  /* W key */
        data->key_w = true;
    else if (keycode == 115)  /* S key */
        data->key_s = true;
    else if (keycode == 97)   /* A key */
        data->key_a = true;
    else if (keycode == 100)  /* D key */
        data->key_d = true;
    return (0);
}

int key_release(int keycode, t_data *data)
{
    printf("Key Released: keycode = %d\n", keycode);
    if (keycode == 119)
        data->key_w = false;
    else if (keycode == 115)
        data->key_s = false;
    else if (keycode == 97)
        data->key_a = false;
    else if (keycode == 100)
        data->key_d = false;
    return (0);
}

/*
    Main entry point.
*/
int main(void)
{
	t_data data;

	data.key_w = false;
	data.key_s = false;
	data.key_a = false;
	data.key_d = false;
	data.delta_accumulator = 0.0;
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_dprintf(2, "Error: mlx_init() failed. Is an X server running?\n");
		return (1);
	}
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Red Square");
	if (!data.win)
	{
		ft_dprintf(2, "Error: mlx_new_window() failed. Check your configuration.\n");
		return (1);
	}
	printf("MLX initialized and window created.\n");
	data.square_x = (WINDOW_WIDTH - SQUARE_SIZE) / 2;
	data.square_y = (WINDOW_HEIGHT - SQUARE_SIZE) / 2;
	printf("Initial square position: (%d, %d)\n", data.square_x, data.square_y);
	if (clock_gettime(CLOCK_MONOTONIC, &data.last_time) != 0)
	{
		perror("clock_gettime failed");
		return (1);
	}
	printf("Initial time set. Starting loop.\n");
	draw_square(&data);
	printf("Initial square drawn.\n");
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 3, 1L<<1, key_release, &data);
	printf("Event hooks registered.\n");
	mlx_loop_hook(data.mlx, update, &data);
	printf("Loop hook registered. Entering MLX loop.\n");
	mlx_loop(data.mlx);
	return (0);
}
