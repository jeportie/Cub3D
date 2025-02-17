/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:54:37 by JeromeP           #+#    #+#             */
/*   Updated: 2024/10/02 09:03:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	ft_intlen(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	size_t	len;

	nbr = (long)n;
	len = ft_intlen(nbr);
	if (nbr < 0)
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		result[0] = '0';
	while (nbr)
	{
		result[len-- - 1] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}
