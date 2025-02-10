/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager_api.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:58:10 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/09 22:08:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_manager.h"
#include "../../include/input.h"

const t_input_manager_api	g_input_manager_methods = {
	.init = init_input_manager,
	.destroy = destroy_input_manager
};

t_input_manager	*create_input_manager(void);
int					init_input_manager(t_input_manager *input_manager);
int					destroy_input_manager(t_input_manager *input_manager);

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
