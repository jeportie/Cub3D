/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:56:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/21 11:25:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/define.h"

int	draw_rays()
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;

	r = 0;
	while (r < RAYS)
	{
		// check horizontal lines
		dof=0;
		float aTan = -1/tan(ra);
		if (ra > M_PI)
		{
			ry = (((int)py >> 6) << 6) - 0,0001;	
			rx = (py -ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < M_PI)
		{
			ry = (((int)py >> 6) << 6) + 64;	
			rx = (py -ry) * aTan + px;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == M_PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if (mp < mapX * mapY && map[mp] == 1)
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof += 1
			}
		}
		r++;
	}
	return (0);
}
