/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconvert_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:39:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:12:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isconvert_spec(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}
