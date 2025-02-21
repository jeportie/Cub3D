/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:12 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 16:47:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	ft_set_north_texture(char *line, t_data *data)
{
	data->parse.config.metadata_count++;
	data->parse.config.textures[0] = ft_strtrim(line, " NO\t\n");
	free(line);
	return (0);
}

int	ft_set_south_texture(char *line, t_data *data)
{
	data->parse.config.metadata_count++;
	data->parse.config.textures[1] = ft_strtrim(line, " SO\t\n");
	free(line);
	return (0);
}

int	ft_set_west_texture(char *line, t_data *data)
{

	data->parse.config.metadata_count++;
	data->parse.config.textures[2] = ft_strtrim(line, " \tWE\n");
	free(line);
	return (0);
}

int	ft_set_east_texture(char *line, t_data *data)
{
	data->parse.config.metadata_count++;
	data->parse.config.textures[3] = ft_strtrim(line, " \tEA\n");
	free(line);
	return (0);
}

// int	ft_set_texture(t_data *data, char *line)
// {
// 	if (ft_strncmp("NO ", line, 3) == 0)
// 		ft_set_north_texture(line, data);
// 	else if (ft_strncmp("SO ", line, 3) == 0)
// 		ft_set_south_texture(line, data);
// 	else if (ft_strncmp("WE ", line, 3) == 0)
// 		ft_set_west_texture(line, data);
// 	else if (ft_strncmp("EA ", line, 3) == 0)
// 		ft_set_east_texture(line, data);
// 	else if (ft_strncmp("F ", line, 2) == 0)
// 		format_floor_color(line, data);
// 	else if (ft_strncmp("C ", line, 2) == 0)
// 		format_ceilling_color(line, data);
// 	return (0);
// }
