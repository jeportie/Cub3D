/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:16 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 18:16:32 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	parse_map(t_data *data)
{
	data->parse.config.map_file_fd
		= ft_open_file(data->parse.config.map_filename);
	skip_metadata(data);
	get_map_index(data);
	ft_end_file(data);
	data->parse.config.map_file_fd
		= ft_open_file(data->parse.config.map_filename);
	ft_go_to_map(data);
	ft_store_map(data);
	replace_spaces(data);
	check_allowed_character(data);
	check_boundaries(data);
	check_player(data);
	floodfill_algo(data, data->parse.map.player_i, data->parse.map.player_j);
	check_algo_floodfill(data);
	restore_map(data);
	data->map = ft_strjoin_array(data->parse.map.layout, data->parse.map.height
			- 1);
	return (0);
}

int	ft_store_map(t_data *data)
{
	ft_calculate_map_height(data);
	ft_end_file(data);
	ft_store(data);
	return (0);
}

int	hole_in_the_map(t_data *data, int i, int j)
{
	int	len;

	if (!is_walkable(data->parse.map.layout[i][j]))
		return (0);
	if (i == 0 || i == data->parse.map.height - 1 || j == 0
		|| j == (int)ft_strlen(data->parse.map.layout[i]) - 1)
		return (1);
	len = ft_strlen(data->parse.map.layout[i - 1]);
	if (j >= len)
		return (1);
	len = ft_strlen(data->parse.map.layout[i + 1]);
	if (j >= len)
		return (1);
	return (0);
}

int	floodfill_algo(t_data *data, int i, int j)
{
	if (i < 0 || i >= data->parse.map.height)
		return (0);
	if (j < 0 || j >= (int)ft_strlen(data->parse.map.layout[i]))
		return (0);
	if (!data->parse.map.layout[i][j])
		return (0);
	if (data->parse.map.layout[i][j] == '1'
		|| data->parse.map.layout[i][j] == 'P')
		return (0);
	else
		data->parse.map.layout[i][j] = 'P';
	floodfill_algo(data, i - 1, j);
	floodfill_algo(data, i + 1, j);
	floodfill_algo(data, i, j - 1);
	floodfill_algo(data, i, j + 1);
	return (0);
}

int	check_algo_floodfill(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->parse.map.height)
	{
		while (j < (int)ft_strlen(data->parse.map.layout[i]))
		{
			if (data->parse.map.layout[i][j] == '1'
				|| data->parse.map.layout[i][j] == 'P')
				j++;
			else
			{
				printf("\033[31mError\nPosition [%d][%d] is unreachable "
					"by the player \n\033[0m", i, j);
				ft_clean_data_and_exit(data);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
