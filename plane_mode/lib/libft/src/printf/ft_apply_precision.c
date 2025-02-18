/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:39:40 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:09:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_new_str(char **new_str, t_format_spec *spec, int total_len,
		int is_negative)
{
	*new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!(*new_str))
	{
		spec->error = ERNOMEM;
		return (1);
	}
	ft_memset(*new_str, '0', total_len);
	if (is_negative)
		(*new_str)[0] = '-';
	return (0);
}

void	ft_apply_precision(t_format_spec spec, char **formatted_content)
{
	int		len;
	char	*new_str;
	int		total_len;
	int		copy_start;
	int		is_negative;

	is_negative = 0;
	if ((*formatted_content)[0] == '-')
		is_negative = 1;
	len = ft_strlen(*formatted_content) - is_negative;
	if (spec.precision <= len && spec.precision != -1)
		return ;
	if (is_negative)
		total_len = spec.precision + 1;
	else
		total_len = spec.precision;
	if (ft_new_str(&new_str, &spec, total_len, is_negative))
		return ;
	copy_start = total_len - len;
	ft_strlcpy(new_str + copy_start, *formatted_content + is_negative, len + 1);
	free(*formatted_content);
	*formatted_content = new_str;
}
