/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:17:09 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 16:46:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	ft_store(t_data *data)
{
	ft_open_file(data->parse.config.map_filename);
	data->parse.map.layout = malloc(sizeof(char *) * data->parse.map.height);
	if (data->parse.map.layout == NULL)
	{
		printf("Error\nMallocError\n");
		ft_clean_data_and_exit(data);
	}
	ft_go_to_map(data);
	ft_fill_layout(data);
	print_map(data);
	return (0);
}

int	replace_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->parse.map.height)
	{
		while (j < (int)ft_strlen(data->parse.map.layout[i]))
		{
			if (data->parse.map.layout[i][j] == ' ')
				data->parse.map.layout[i][j] = '1';
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_allowed_character(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->parse.map.height)
	{
		j = 0;
		while (j < (int)ft_strlen(data->parse.map.layout[i]))
		{
			if (data->parse.map.layout[i][j] == 'N' || data->parse.map.layout[i][j] == 'S'
				|| data->parse.map.layout[i][j] == 'W'
				|| data->parse.map.layout[i][j] == 'E'
				|| data->parse.map.layout[i][j] == '1'
				|| data->parse.map.layout[i][j] == '0')
				j++;
			else
			{
				printf("\033[31mError\nCharacter : |%c| Pos[%d][%d]Unauthorized\nAuthorized characters are : '1' '0' 'N' 'S' 'E' 'W'\n\033[0m",
					data->parse.map.layout[i][j], i, j);
				ft_clean_data_and_exit(data);
			}
		}
		i++;
	}
	return (0);
}

char	*ft_trim_line(char *line)
{
	char	*trimmed;

	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, "\t\n\r");
	if (!trimmed)
		return (line);
	free(line);
	return (trimmed);
}


int	ft_initialize_layout(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->parse.map.height)
	{
		data->parse.map.layout[i] = NULL;
		i++;
	}
	return (0);
}
