/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:31:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/24 17:31:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	print_map(void)
{
	int	row;
	int	col;

	ft_printf("Map layout (0=floor, 1=wall, P=player):\n");
	row = 0;
	while (row < MAP_HEIGHT)
	{
		col = 0;
		while (col < MAP_WIDTH)
		{
			ft_printf("%c ", g_map[row * MAP_WIDTH + col]);
			col++;
		}
		ft_printf("\n");
		row++;
	}
	ft_printf("\n");
	return (0);
}
