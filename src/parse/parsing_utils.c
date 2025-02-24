/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:08:00 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/24 15:12:24 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

int	correct_extension(char *file_name)
{
	if (ft_strlen(file_name) < 5)
		return (1);
	if (file_name[ft_strlen(file_name) - 1] != 'b')
		return (1);
	if (file_name[ft_strlen(file_name) - 2] != 'u')
		return (1);
	if (file_name[ft_strlen(file_name) - 3] != 'c')
		return (1);
	if (file_name[ft_strlen(file_name) - 4] != '.')
		return (1);
	return (0);
}

int	print_map(t_data *data)
{
	int	i;

	i = 0;
	printf("_____________________________________\n__________________MAP__"
		"_______________\n");
	while (i < data->parse.map.height)
	{
		printf("line [%d] = |%s|\n", i, data->parse.map.layout[i]);
		i++;
	}
	return (0);
}

int	ft_trim_tab(char **rgb_tab)
{
	int		i;
	char	*tmp;

	i = 0;
	if (rgb_tab)
	{
		while (rgb_tab[i])
		{
			tmp = rgb_tab[i];
			rgb_tab[i] = ft_strtrim(rgb_tab[i], " C F \t\n");
			free(tmp);
			i++;
		}
	}
	return (0);
}

void	ft_print_tab(char **rgb_tab)
{
	int	i;
	int	j;

	i = 0;
	while (rgb_tab[i])
	{
		j = 0;
		while (rgb_tab[i][j])
		{
			printf("rgb[%d][%d] = %c\n", i, j, rgb_tab[i][j]);
			j++;
		}
		printf("___________\n");
		i++;
	}
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		printf("str[%d] = %c\n", i, str[i]);
		if (ft_isdigit(str[i]))
			i++;
		else
		{
			return (0);
			printf("-----------\n");
		}
	}
	printf("-----------\n");
	return (1);
}
