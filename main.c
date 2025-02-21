/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/21 17:02:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/define.h"
#include "include/player.h"
#include "include/input.h"
#include "include/engine.h"
#include "include/error.h"
#include "include/functions.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || correct_extension(argv[1]))
	{
		printf("\033[31mError\n : %s\nUse the prog as followed :  "
			"./cub3d map.cub || .cub extension !\033[0m\n", strerror(errno));
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	data.toogle_map = true;
	data.toogle_dda = true;
	data.toogle_rays = true;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
	data.parse.config.map_filename = argv[1];
	data.parse.config.map_file_fd = ft_open_file(data.parse.config.map_filename);
	if (data.parse.config.map_file_fd == -1)
		exit(1);
	ft_initialize(&data);
	parse(&data);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
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
	if (init_texture(&data))
	{
		ft_dprintf(2, ERR_TEX_INIT);
		return (1);
	}
	player_init(&data);
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
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
	ft_clean_data_and_exit(&data);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
	return (0);
}
