/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:39:22 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:04:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_fill_base(unsigned int nbr, int size, char *base, char *res)
{
	int	len;
	int	i;

	len = ft_strlen(base);
	i = size - 1;
	if (nbr == 0)
		res[i] = base[0];
	while (nbr)
	{
		res[i--] = base[nbr % len];
		nbr /= len;
	}
	res[size] = '\0';
	return (res);
}

char	*ft_utoa_base(unsigned int nbr, char *base)
{
	int		len;
	int		size;
	char	*res;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	len = ft_strlen(base);
	size = ft_nbr_len(nbr, len);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	return (ft_fill_base(nbr, size, base, res));
}
