/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_texture_doublon.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:28:54 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 16:45:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	ft_check_north_doublon(char *line, t_data *data)
{
	if (ft_strncmp("NO ", line, 3) == 0)
		data->parse.config.flags[0]++;
	if (data->parse.config.flags[0] > 1)
	{
		printf("\033[31mError:\nMultiple NORTH texture\n\033[0m");
		free(line);
		ft_clean_data_and_exit(data);
	}
	return (0);
}

int	ft_check_south_doublon(char *line, t_data *data)
{
	if (ft_strncmp("SO ", line, 3) == 0)
		data->parse.config.flags[1]++;
	if (data->parse.config.flags[1] > 1)
	{
		printf("\033[31mError:\nMultiple SOUTH texture\n\033[0m");
		free(line);
		ft_clean_data_and_exit(data);
	}
	return (0);
}

int	ft_check_west_doublon(char *line, t_data *data)
{
	if (ft_strncmp("WE ", line, 3) == 0)
		data->parse.config.flags[2]++;
	if (data->parse.config.flags[2] > 1)
	{
		printf("\033[31mError:\nMultiple WEST texture\n\033[0m");
		free(line);
		ft_clean_data_and_exit(data);
	}
	return (0);
}

int	ft_check_east_doublon(char *line, t_data *data)
{
	if (ft_strncmp("EA ", line, 3) == 0)
		data->parse.config.flags[3]++;
	if (data->parse.config.flags[3] > 1)
	{
		printf("\033[31mError:\nMultiple EAST texture\n\033[0m");
		ft_clean_data_and_exit(data);
	}
	return (0);
}
