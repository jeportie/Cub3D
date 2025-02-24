/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:09:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/02/23 21:34:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

int	put_pixel_to_image(t_coord pos, int color, t_image *img)
{
	char	*dst;

	if (pos.x < 0 || pos.x >= WINDOW_WIDTH
		|| pos.y < 0 || pos.y >= WINDOW_HEIGHT)
		return (-1);
	dst = img->addr + ((int)pos.y * img->line_len
			+ (int)pos.x * (img->bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}
