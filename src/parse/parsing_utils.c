/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:08:00 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 14:59:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/functions.h"

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
