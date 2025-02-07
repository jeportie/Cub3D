/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/07 11:17:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/player.h"
#include "include/input.h"
#include "include/engine.h"
#include "include/error.h"

char	g_map[MAP_SIZE + 1] = {
	"11111001"
	"10000001"
	"10000001"
	"10011001"
	"10010001"
	"1000P001"
	"10000001"
	"11111111"
};

int	main(void)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.toogle_map = true;
	data.toogle_dda = true;
	data.toogle_rays = true;
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
		ft_dprintf(2, "Error: Texture initialization failed.\n");
		return (1);
	}
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
