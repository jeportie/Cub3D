/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:44:12 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 15:25:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/input.h"
#include "../../include/functions.h"

int	close_window(t_data *data)
{
	int	i;

	ft_printf("Window close (X button) pressed. Exiting.\n");
	i = 0;
	free(data->map);
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->walls[i].img_ptr);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(data->mlx, data->img[i].img_ptr);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_clean_data_and_exit(data);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	int	i;

	ft_printf("Key Pressed: keycode = %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC pressed. Exiting.\n");
		free(data->map);
		i = 0;
		while (i < 4)
		{
			mlx_destroy_image(data->mlx, data->walls[i].img_ptr);
			i++;
		}
		i = 0;
		while (i < 2)
		{
			mlx_destroy_image(data->mlx, data->img[i].img_ptr);
			i++;
		}
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_clean_data_and_exit(data);
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
		data->toogle_texture_mode = !data->toogle_texture_mode;
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
