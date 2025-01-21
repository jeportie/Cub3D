/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 09:46:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/input.h"

int	key_press(int keycode, t_data *data)
{
	ft_printf("Key Pressed: keycode = %d\n", keycode);
	if (keycode == 65307)
	{
		ft_printf("ESC pressed. Exiting.\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 65361)
		data->player.rot_left = true;
	else if (keycode == 65363)
		data->player.rot_right = true;
	else if (keycode == 119)
		data->player.move_up = true;
	else if (keycode == 115)
		data->player.move_down = true;
	else if (keycode == 97)
		data->player.move_left = true;
	else if (keycode == 100)
		data->player.move_right = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	ft_printf("Key Released: keycode = %d\n", keycode);
	if (keycode == 65361)
		data->player.rot_left = false;
	else if (keycode == 65363)
		data->player.rot_right = false;
	else if (keycode == 119)
		data->player.move_up = false;
	else if (keycode == 115)
		data->player.move_down = false;
	else if (keycode == 97)
		data->player.move_left = false;
	else if (keycode == 100)
		data->player.move_right = false;
	return (0);
}
