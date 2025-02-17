/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_safe_cos_sin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:17:15 by jeportie          #+#    #+#             */
/*   Updated: 2025/01/25 23:17:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/compute.h"

float	get_safe_cos(float angle)
{
	float	cos_a;

	cos_a = cosf(angle);
	if (fabsf(cos_a) < EPSILON)
	{
		if (cos_a > 0)
			return (EPSILON);
		else
			return (-EPSILON);
	}
	return (cos_a);
}

float	get_safe_sin(float angle)
{
	float	sin_a;

	sin_a = sinf(angle);
	if (fabsf(sin_a) < EPSILON)
	{
		if (sin_a > 0)
			return (EPSILON);
		else
			return (-EPSILON);
	}
	return (sin_a);
}
