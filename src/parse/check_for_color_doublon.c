/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_color_doublon.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:29:56 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 17:56:41 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	ft_check_floor_doublon(char *line, t_data *data)
{
	if (ft_strncmp("F ", line, 2) == 0)
		data->parse.config.flags[4]++;
	if (data->parse.config.flags[4] > 1)
	{
		printf("\033[31mError:\nMultiple FLOOR COLOR\n\033[0m");
		free(line);
		ft_clean_data_and_exit(data);
	}
	return (0);
}

int	ft_check_ceilling_doublon(char *line, t_data *data)
{
	if (ft_strncmp("C ", line, 2) == 0)
		data->parse.config.flags[5]++;
	if (data->parse.config.flags[5] > 1)
	{
		printf("\033[31mError:\nMultiple CEILLING COLOR\n\033[0m");
		free(line);
		ft_clean_data_and_exit(data);
	}
	return (0);
}
