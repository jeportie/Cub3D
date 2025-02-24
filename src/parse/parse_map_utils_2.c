/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:17:09 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 13:01:53 by anastruc         ###   ########.fr       */
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

int	is_allowed(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E' || c == '1' || c == '0')
		return (1);
	else
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
			if (is_allowed(data->parse.map.layout[i][j]))
				j++;
			else
			{
				printf("\033[31mError\nCharacter : |%c| Pos[%d][%d] \
					Unauthorized\nAuthorized characters are\
					 : '1' '0' 'N' 'S' 'E' 'W'\n\033[0m",
					data->parse.map.layout[i][j], i, j);
				ft_clean_data_and_exit(data);
			}
		}
		i++;
	}
	return (0);
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
