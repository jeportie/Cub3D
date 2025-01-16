/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:36:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 07:05:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
 * ft_memset - Fill a block of memory with a specific value.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem_src;

	mem_src = (unsigned char *)s;
	while (n--)
		*mem_src++ = (unsigned char)c;
	return (s);
}
