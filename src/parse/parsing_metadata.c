/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:36 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 16:47:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	parse(t_data *data)
{
	// check_extension(data)
	ft_check_for_doublon(data);
	ft_store_metadata(data);
	check_config_data(data);
	ft_end_file(data);
	parse_map(data);
	return (0);
}

// int	check_extension(t_data *data)
// {

// }
int	ft_store_metadata(t_data *data)
{
	char	*line;

	data->parse.config.map_file_fd = ft_open_file(data->parse.config.map_filename);
	while (1)
	{
		line = get_next_line(data->parse.config.map_file_fd);
		printf("Line[%d] = |%s|\n", data->parse.map.begin_map_index, line);
		if (line == NULL || data->parse.config.metadata_count == 6)
		{
			if (line != NULL)
				return (free(line), 1);
			return (1);
		}
		data->parse.map.begin_map_index++;
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
		{
			free(line);
			continue ;
		}
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
		ft_check_floor_doublon(line, data);
		ft_check_ceilling_doublon(line, data);
		printf("line = |%s|\n", line);
		free(line);
	}
	return (0);
}

int	check_config_data(t_data *data)
{
	check_texture(data);
	return (0);
}

int	missing_texture(t_data *data)
{
	int	i;
	i = 0;
	while (i < 4)
	{
		if (data->parse.config.textures[i])
			i++;
		else
		{
			printf("\033[31mError\n:Missing texture.\nTexture File name : |%s|\n%s\033[0m\n", data->parse.config.textures[i], strerror(errno));
			ft_clean_data_and_exit(data);
		}
	}
	return (0);
}
int	check_texture(t_data *data)
{
	int	i;
	int	fd;

	missing_texture(data);
	i = 0;
	while (i < 4)
	{
		fd = open(data->parse.config.textures[i], O_RDONLY);
		data->parse.config.textures_files_fd[i] = fd;
		if (fd == -1)
		{
			printf("\033[31mError\n:Issue with one of the texture.\nTexture File name : |%s|\n%s\033[0m\n",
				data->parse.config.textures[i], strerror(errno));
			ft_clean_data_and_exit(data);
		}
		printf("\033[32m Texture file OK \n|%s|\n\033[0m\n",
			data->parse.config.textures[i]);
		i++;
	}
	return (0);
}
