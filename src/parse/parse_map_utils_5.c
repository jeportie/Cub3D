/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:54:13 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 17:51:40 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	print_err_message_boundaries(t_data *data, int i, int j, int type)
{
	if (type == 1)
		printf("\033[31mError\nThe Map must be closed "
			"(First row : Point[%d][%d])\n\033[0m", j, i);
	if (type == 2)
		printf("\033[31mError\nThe Map must be closed "
			"(Last row : Point[%d][%d])\n\033[0m",
			data->parse.map.height - 1, j);
	if (type == 3)
		printf("\033[31mError\nThe Map must be closed "
			"(First column : Point[%d][%d])\n\033[0m", i, j);
	if (type == 4)
		printf("\033[31mError\nThe Map must be closed "
			"(Last column : Point[%d][%d])\n\033[0m",
			i, j);
	ft_clean_data_and_exit(data);
	return (0);
}

int	check_config_data(t_data *data)
{
	check_texture(data);
	missing_color(data);
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
			printf("\033[31mError\n:Missing texture.\nTexture File name : |%s|"
				"\nTextures will be set to default\033[0m\n",
				data->parse.config.textures[i]);
		}
	}
	return (0);
}


int	missing_color(t_data *data)
{

	if (data->parse.config.ceiling_color == -1)
	{
		printf("\033[31mError\n:Missing ceilling color\n\033[0m");
		ft_clean_data_and_exit(data);
	}
	if (data->parse.config.floor_color == -1)
	{
		printf("\033[31mError\n:Missing Floor color\n\033[0m");
		ft_clean_data_and_exit(data);
	}
	return (0);
}
