/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:26:31 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 14:56:04 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	rgb_to_hex(int rgb[3])
{
	int	color;

	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (color);
}

int	check_ceiling_color(t_data *data, int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
		{
			printf("\033[31mError\n:Issue with the RGB ceiling color."
				"\n%s\033[0m\n",
				strerror(errno));
			ft_clean_data_and_exit(data);
		}
		i++;
	}
	return (0);
}

int	format_ceilling_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;
	int		color[3];

	i = 0;
	rgb_tab = ft_split(line, 44);
	ft_trim_tab(rgb_tab);
	while (rgb_tab[i])
		i++;
	if (i != 3)
		ft_free_exit(line, rgb_tab, data, 1);
	i = 0;
	while (i < 3)
	{
		if (!ft_is_number(rgb_tab[i]))
			ft_free_exit(line, rgb_tab, data, 2);
		color[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
	check_ceiling_color(data, color);
	data->parse.config.ceiling_color = rgb_to_hex(color);
	data->parse.config.metadata_count++;
	free(line);
	free_char_tab(rgb_tab);
	return (0);
}

int	check_floor_color(t_data *data, int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
		{
			printf("\033[31mError\n:Issue with the RGB floor color :"
				"%d\n\033[0m\n", color[i]);
			ft_clean_data_and_exit(data);
		}
		printf("\033[32mRGB floor color OK \n%d\n\033[0m\n", color[i]);
		i++;
	}
	return (0);
}

int	format_floor_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;
	int		color[3];

	i = 0;
	rgb_tab = ft_split(line, 44);
	ft_trim_tab(rgb_tab);
	while (rgb_tab[i])
		i++;
	if (i != 3)
		ft_free_exit(line, rgb_tab, data, 1);
	i = 0;
	while (i < 3)
	{
		if (!ft_is_number(rgb_tab[i]))
			ft_free_exit(line, rgb_tab, data, 2);
		color[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
	check_ceiling_color(data, color);
	data->parse.config.floor_color = rgb_to_hex(color);
	data->parse.config.metadata_count++;
	free(line);
	free_char_tab(rgb_tab);
	return (0);
}
