/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:14:24 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/11 22:33:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_manager.h"
#include "../../include/input.h"

int	key_press(int keycode, t_game *game)
{
	ft_printf("Key Pressed: keycode = %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC pressed. Exiting.\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == KEY_LEFT_ARROW)
		game->player.rot_left = true;
	else if (keycode == KEY_RIGHT_ARROW)
		game->player.rot_right = true;
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		game->player.move_up = true;
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		game->player.move_down = true;
	else if (keycode == KEY_A)
		game->player.move_left = true;
	else if (keycode == KEY_D)
		game->player.move_right = true;
	else if (keycode == KEY_F1)
		game->toogle_rays = !game->toogle_rays;
	else if (keycode == KEY_F2)
		game->toogle_dda = !game->toogle_dda;
	else if (keycode == KEY_F3)
		game->toogle_texture_mode = !game->toogle_texture_mode;
	else if (keycode == KEY_F4)
		game->toogle_map = !game->toogle_map;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	ft_printf("Key Released: keycode = %d\n", keycode);
	if (keycode == KEY_LEFT_ARROW)
		game->player.rot_left = false;
	else if (keycode == KEY_RIGHT_ARROW)
		game->player.rot_right = false;
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		game->player.move_up = false;
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		game->player.move_down = false;
	else if (keycode == KEY_A)
		game->player.move_left = false;
	else if (keycode == KEY_D)
		game->player.move_right = false;
	return (0);
}
