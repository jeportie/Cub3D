/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:44:07 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:12:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_nbr_len(unsigned long long nbr, int base_len)
{
	int	len;

	len = 1;
	while (nbr / base_len)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
