/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/05 21:06:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/input.h"

int	key_press(int keycode, t_data *data)
{
	ft_printf("Key Pressed: keycode = %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC pressed. Exiting.\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == KEY_LEFT_ARROW)
		data->player.rot_left = true;
	else if (keycode == KEY_RIGHT_ARROW)
		data->player.rot_right = true;
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		data->player.move_up = true;
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		data->player.move_down = true;
	else if (keycode == KEY_A)
		data->player.move_left = true;
	else if (keycode == KEY_D)
		data->player.move_right = true;
	else if (keycode == KEY_F1)
		data->toogle_rays = !data->toogle_rays;
	else if (keycode == KEY_F2)
		data->toogle_dda = !data->toogle_dda;
	else if (keycode == KEY_F3)
		data->toogle_texture_mode = !data->toogle_texture_mode;
	else if (keycode == KEY_F4)
		data->toogle_map = !data->toogle_map;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	ft_printf("Key Released: keycode = %d\n", keycode);
	if (keycode == KEY_LEFT_ARROW)
		data->player.rot_left = false;
	else if (keycode == KEY_RIGHT_ARROW)
		data->player.rot_right = false;
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		data->player.move_up = false;
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		data->player.move_down = false;
	else if (keycode == KEY_A)
		data->player.move_left = false;
	else if (keycode == KEY_D)
		data->player.move_right = false;
	return (0);
}
