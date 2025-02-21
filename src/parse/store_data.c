/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:35:49 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 16:47:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	ft_store_metadatas(t_data *data)
{
	char	*line;

	data->parse.config.map_file_fd = ft_open_file(data->parse.config.map_filename);
	while (1)
	{
		line = get_next_line(data->parse.config.map_file_fd);
		data->parse.map.begin_map_index++;
		printf("Line[%d] = |%s|\n", data->parse.map.begin_map_index, line);
		if (line == NULL || data->parse.config.metadata_count == 6)
		{
			if (line != NULL)
				return (free(line), 1);
			return (1);
		}
	//	ft_set_texture(data, line);
		free(line);
		continue ;
	}
	return (0);
}
