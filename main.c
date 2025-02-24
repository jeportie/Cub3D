/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 12:13:04 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/define.h"
#include "include/player.h"
#include "include/input.h"
#include "include/engine.h"
#include "include/error.h"
#include "include/functions.h"

int	init_and_parse(t_data *data, int argc, char **argv)
{
	if (argc != 2 || correct_extension(argv[1]))
	{
		printf("\033[31mError\n : %s\nUse the prog as followed :  "
			"./cub3d map.cub || .cub extension !\033[0m\n", strerror(errno));
		return (0);
	}
	ft_memset(data, 0, sizeof(t_data));
	data->parse.config.map_filename = argv[1];
	data->parse.config.map_file_fd
		= ft_open_file(data->parse.config.map_filename);
	if (data->parse.config.map_file_fd == -1)
		exit(1);
	ft_initialize(data);
	parse(data);
	return (1);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_dprintf(2, ERR_MLX_INIT);
		return (0);
	}
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, GAME_TITLE);
	if (!data->win)
	{
		ft_dprintf(2, ERR_MLX_WINDOW);
		return (0);
	}
	ft_printf("MLX initialized and window created.\n");
	init_image(data);
	data->toogle_texture_mode = true;
	if (init_wall_texture(data))
	{
		ft_dprintf(2, ERR_TEX_INIT);
		data->toogle_texture_mode = false;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!init_and_parse(&data, argc, argv))
		return (0);
	if (!init_mlx(&data))
		return (0);
	player_init(&data);
	if (clock_gettime(CLOCK_MONOTONIC, &data.last_time) != 0)
	{
		ft_dprintf(2, ERR_GETTIME);
		return (1);
	}
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, 0L, close_window, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	ft_printf("Entering MLX event loop.\n");
	mlx_loop(data.mlx);
	ft_clean_data_and_exit(&data);
	return (0);
}
