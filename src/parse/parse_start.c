/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:50:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/24 17:51:28 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	test_parsing_metadata(t_data *data)
{
	printf("Floor color : %d\n", data->parse.config.floor_color);
	printf("Ceilling color : %d\n", data->parse.config.ceiling_color);
	return (0);
}

int	ft_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("\033[31mError\n :%s The file doesn't exist or"
			"can not be open\033[0m\n", strerror(errno));
		return (-1);
	}
	else
		return (fd);
}

int	ft_initialize(t_data *data)
{
	int	i;

	i = 0;
	data->parse.map.layout = NULL;
	data->parse.map.begin_map_index = 0;
	data->parse.config.metadata_count = 0;
	data->parse.map.height = 0;
	data->parse.map.width = 0;
	data->parse.config.ceiling_color = -1;
	data->parse.config.floor_color = -1;
	while (i < 4)
	{
		data->parse.config.textures[i] = NULL;
		data->parse.config.textures_files_fd[i] = -1;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		data->parse.config.flags[i] = 0;
		i++;
	}
	return (1);
}

int	ft_end_file(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(data->parse.config.map_file_fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(data->parse.config.map_file_fd);
	return (0);
}
