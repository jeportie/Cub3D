/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:36:10 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:07:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*memloc_dest;
	const unsigned char	*memloc_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	memloc_dest = (unsigned char *)dest;
	memloc_src = (const unsigned char *)src;
	if (memloc_dest < memloc_src)
	{
		while (n-- && memloc_dest && memloc_src)
			*memloc_dest++ = *memloc_src++;
	}
	else
	{
		memloc_dest += n;
		memloc_src += n;
		while (n--)
		{
			memloc_dest--;
			memloc_src--;
			*memloc_dest = *memloc_src;
		}
	}
	return (dest);
}
