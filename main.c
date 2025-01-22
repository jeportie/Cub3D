/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/22 16:45:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/player.h"
#include "include/minimap.h"
#include "include/input.h"
#include "include/engine.h"
#include "include/error.h"

int	main(void)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_dprintf(2, ERR_MLX_INIT);
		return (1);
	}
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
	if (!data.win)
	{
		ft_dprintf(2, ERR_MLX_WINDOW);
		return (1);
	}
	ft_printf("MLX initialized and window created.\n");
	init_image(&data);
	player_init(&data);
	print_map();
	if (clock_gettime(CLOCK_MONOTONIC, &data.last_time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (1);
	}
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	ft_printf("Entering MLX event loop.\n");
	mlx_loop(data.mlx);
	return (0);
}


