/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:49:36 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:12:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_find_end(const char *start, t_format_spec *spec)
{
	char	*ptr;

	if (!start)
		return (NULL);
	ptr = (char *)start;
	while (*ptr && (ft_isflag(*ptr) || ft_isconvert_spec(*ptr)))
	{
		if (ft_isconvert_spec(*ptr))
		{
			spec->type = *ptr;
			return (ptr);
		}
		ptr++;
	}
	return (NULL);
}

t_format_spec	ft_parse_format(const char **format)
{
	t_format_spec	spec;
	char			*end;

	ft_memset(&spec, 0, sizeof(t_format_spec));
	spec.precision = -1;
	if (!format || !*format || **format != '%')
		return (spec);
	(*format)++;
	end = ft_find_end(*format, &spec);
	if (!end)
	{
		spec.error = ERNOFORMAT;
		return (spec);
	}
	ft_parse_flags(*format, &spec);
	*format = end;
	return (spec);
}
