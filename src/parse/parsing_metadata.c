/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:36 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/26 11:54:32 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	parse(t_data *data)
{
	ft_check_for_doublon(data);
	ft_store_metadata(data);
	check_config_data(data);
	ft_end_file(data);
	parse_map(data);
	return (0);
}

int	set_texture(t_data *data, char *line)
{
	if (ft_strncmp("NO ", line, 3) == 0)
		ft_set_north_texture(line, data);
	else if (ft_strncmp("SO ", line, 3) == 0)
		ft_set_south_texture(line, data);
	else if (ft_strncmp("WE ", line, 3) == 0)
		ft_set_west_texture(line, data);
	else if (ft_strncmp("EA ", line, 3) == 0)
		ft_set_east_texture(line, data);
	else if (ft_strncmp("F ", line, 2) == 0)
		format_floor_color(line, data);
	else if (ft_strncmp("C ", line, 2) == 0)
		format_ceilling_color(line, data);
	else
		free(line);
	return (0);
}

int	ft_store_metadata(t_data *data)
{
	char	*line;

	data->parse.config.map_file_fd
		= ft_open_file(data->parse.config.map_filename);
	while (1)
	{
		line = get_next_line(data->parse.config.map_file_fd);
		if (line == NULL || data->parse.config.metadata_count == 6)
		{
			if (line != NULL)
				return (free(line), 1);
			return (1);
		}
		data->parse.map.begin_map_index++;
		set_texture(data, line);
	}
	return (0);
}

int	ft_check_for_doublon(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(data->parse.config.map_file_fd);
		if (line == NULL)
			return (1);
		ft_check_north_doublon(line, data);
		ft_check_south_doublon(line, data);
		ft_check_west_doublon(line, data);
		ft_check_east_doublon(line, data);
		ft_check_ceilling_doublon(line, data);
		ft_check_floor_doublon(line, data);
		free(line);
	}
	return (0);
}

int	check_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->parse.config.textures[i])
		{
			printf("\033[31mError\n:Missing texture.\nTexture File name : |%s|"
				"\033[0m\n", data->parse.config.textures[i]);
			ft_clean_data_and_exit(data);
		}
		else
			try_open_texture_file(data, i);
		i++;
	}
	return (0);
}
