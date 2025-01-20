/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/20 23:24:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/player.h"
#include "include/minimap.h"
#include "include/input.h"
#include "include/engine.h"

int	update(t_data *data)
{
	struct timespec	current_time;
	double			delta;
	double			time_step;

	if (clock_gettime(CLOCK_MONOTONIC, &current_time) != 0)
	{
		perror("clock_gettime failed");
		return (1);
	}
	delta = get_time_in_seconds(current_time) - get_time_in_seconds(data->last_time);
	data->last_time = current_time;
	data->delta_accumulator += delta;
	ft_printf("delta = %.6f, accumulator = %.6f\n", delta, data->delta_accumulator);
	fflush(stdout);
	time_step = 1.0 / 60.0;
	while (data->delta_accumulator >= time_step)
	{
		player_update(data, time_step);
		data->delta_accumulator -= time_step;
	}
	clear_image(&data->img, 0x000000);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

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
	init_image(&data);
	compute_map_offset(&data);
	player_init(&data);
	print_map();
	if (clock_gettime(CLOCK_MONOTONIC, &data.last_time) != 0)
	{
		perror("clock_gettime failed");
		return (1);
	}
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, update, &data);
	printf("Entering MLX event loop.\n");
	fflush(stdout);
	mlx_loop(data.mlx);
	return (0);
}
