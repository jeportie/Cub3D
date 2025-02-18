/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:46:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:12:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_parse_width(const char *format, t_format_spec *spec, size_t *i)
{
	spec->width = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		spec->width = spec->width * 10 + (format[*i] - '0');
		(*i)++;
	}
}

static void	ft_parse_precision(const char *format, t_format_spec *spec,
		size_t *i)
{
	if (format[*i] == '.')
	{
		(*i)++;
		spec->precision = 0;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			spec->precision = spec->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
}

static void	ft_zero_minus_flags(const char *format, t_format_spec *spec,
		size_t *i)
{
	if (format[*i] == '0' && !spec->flag_minus && spec->width == 0)
	{
		spec->flag_zero = 1;
	}
	else if (format[*i] == '-')
	{
		spec->flag_minus = 1;
		spec->flag_zero = 0;
	}
	(*i)++;
}

static void	ft_psh_flags(const char *format, t_format_spec *spec, size_t *i)
{
	if (format[*i] == '+')
	{
		spec->flag_plus = 1;
		spec->flag_space = 0;
	}
	else if (format[*i] == ' ' && !spec->flag_plus)
	{
		spec->flag_space = 1;
	}
	else if (format[*i] == '#')
	{
		spec->flag_hash = 1;
	}
	(*i)++;
}

void	ft_parse_flags(const char *format, t_format_spec *spec)
{
	size_t	i;

	i = 0;
	while (ft_isflag(format[i]) && format[i] != spec->type)
	{
		if (format[i] == '0' || format[i] == '-')
			ft_zero_minus_flags(format, spec, &i);
		else if (ft_strchr("+# ", format[i]))
			ft_psh_flags(format, spec, &i);
		else if (ft_isdigit(format[i]) && format[i] != '0')
			ft_parse_width(format, spec, &i);
		else if (format[i] == '.' && spec->type != 'p' && spec->type != 'c')
			ft_parse_precision(format, spec, &i);
		else
		{
			spec->error = ERNOFORMAT;
			break ;
		}
	}
}
