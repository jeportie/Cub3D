/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:36:02 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:06:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	if (!dest && !src)
		return (NULL);
	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	while (n-- && mem_dest && mem_src)
		*mem_dest++ = *mem_src++;
	return (dest);
}
