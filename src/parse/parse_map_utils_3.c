/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:21:48 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 15:09:35 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	check_first_last_row(t_data *data)
{
	int	j;

	j = 0;
	while (j < ((int)ft_strlen(data->parse.map.layout[0])))
	{
		if (data->parse.map.layout[0][j] != '1')
			print_err_message_boundaries(data, 0, j, 1);
		j++;
	}
	j = 0;
	while (j < ((int)ft_strlen(data->parse.map.layout[data->parse.map.height
					- 1])))
	{
		if (data->parse.map.layout[data->parse.map.height - 1][j] != '1')
			print_err_message_boundaries(data, data->parse.map.height - 1, j,
				2);
		j++;
	}
	return (0);
}

int	check_first_last_column(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->parse.map.height - 1)
	{
		if (data->parse.map.layout[i][0] != '1')
			print_err_message_boundaries(data, i, 0, 3);
		i++;
	}
	i = 0;
	while (i < data->parse.map.height - 1)
	{
		if (data->parse.map.layout[i][ft_strlen(data->parse.map.layout[i])
			- 1] != '1')
			print_err_message_boundaries(data, i,
				ft_strlen(data->parse.map.layout[i]) - 1, 4);
		i++;
	}
	return (0);
}

int	ft_check_flag(int flag, t_data *data)
{
	if (flag == 0)
	{
		printf("\033[31mError\nMissing player's position\n\033[0m");
		return (ft_clean_data_and_exit(data));
	}
	else if (flag > 1)
	{
		printf("\033[31mError\nToo many player's positions. Extra at[%d][%d]"
			"Extra = %d\n\033[0m", data->parse.map.player_i,
			data->parse.map.player_j,
			flag - 1);
		return (ft_clean_data_and_exit(data));
	}
	else
		return (0);
}

int	check_player(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	j = 0;
	while (i < data->parse.map.height)
	{
		while (j < (int)ft_strlen(data->parse.map.layout[i]))
		{
			if (set_player_position(i, j, data))
				flag++;
			j++;
		}
		j = 0;
		i++;
	}
	ft_check_flag(flag, data);
	return (0);
}

int	set_player_position(int i, int j, t_data *data)
{
	if (data->parse.map.layout[i][j] == 'N'
		|| data->parse.map.layout[i][j] == 'S'
		|| data->parse.map.layout[i][j] == 'W'
		|| data->parse.map.layout[i][j] == 'E')
	{
		data->parse.map.player_i = i;
		data->parse.map.player_j = j;
		data->parse.map.player_dir = data->parse.map.layout[i][j];
		return (1);
	}
	else
		return (0);
}
