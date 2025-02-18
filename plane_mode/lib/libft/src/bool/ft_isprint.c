/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:04:32 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 08:51:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
 * Check if the char is printable
 */

bool	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (true);
	return (false);
}
