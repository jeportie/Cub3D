/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:11:17 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 17:01:52 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	ft_free_exit(char *line, char **rgb_tab, t_data *data, int i)
{
	free(line);
	free_char_tab(rgb_tab);
	if (i == 1)
		printf("\033[31mError\n!RGB! Each color must be made of exactly 3"
			"numbers serpareted by a coma\n\033[0m");
	else
		printf("\033[31mError\nDIGIT ONLY : Each color must be made of exactly "
			"3 numbers serpareted by a coma\n\033[0m");
	return (ft_clean_data_and_exit(data));
}

int	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

int	ft_clean_layout(t_data *data)
{
	int	i;

	i = 0;
	if (data == NULL || data->parse.map.layout == NULL)
		return (1);
	while (i < data->parse.map.height)
	{
		if (data->parse.map.layout[i] != NULL)
			free(data->parse.map.layout[i]);
		i++;
	}
	free(data->parse.map.layout);
	data->parse.map.layout = NULL;
	return (0);
}

int	ft_clean_data_and_exit(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(data->parse.config.map_file_fd);
		if (line == NULL)
			break ;
		free(line);
	}
	while (i < 4)
	{
		if (data->parse.config.textures_files_fd[i] != -1)
			close(data->parse.config.textures_files_fd[i]);
		if (data->parse.config.textures[i])
			free(data->parse.config.textures[i]);
		i++;
	}
	ft_clean_layout(data);
	exit(1);
}
