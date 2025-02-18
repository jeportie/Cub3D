/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:21:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:57:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_issign(int c, int *sign)
{
	if (c == '+')
		return (1);
	if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	digit;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i], &sign))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		result = result * 10 + digit;
		i++;
	}
	return (result * sign);
}
