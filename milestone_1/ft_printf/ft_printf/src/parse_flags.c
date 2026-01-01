/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:37:37 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:37:44 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.precision_set = 0;
	return (flags);
}

static void	parse_flag_chars(const char *format, int *i, t_flags *flags)
{
	while (format[*i] == '-' || format[*i] == '0' || format[*i] == '#'
		|| format[*i] == '+' || format[*i] == ' ')
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		(*i)++;
	}
	if (flags->minus)
		flags->zero = 0;
}

static void	parse_width(const char *format, int *i, t_flags *flags,
		va_list args)
{
	if (format[*i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->width = -flags->width;
			flags->minus = 1;
			flags->zero = 0;
		}
		(*i)++;
	}
	else if (ft_isdigit(format[*i]))
	{
		flags->width = 0;
		while (ft_isdigit(format[*i]))
		{
			flags->width = flags->width * 10 + (format[*i] - '0');
			(*i)++;
		}
		if (format[*i] == '%')
			flags->width = 0;
	}
}

static void	parse_precision(const char *format, int *i, t_flags *flags,
		va_list args)
{
	if (format[*i] == '.')
	{
		flags->precision_set = 1;
		(*i)++;
		if (format[*i] == '*')
		{
			flags->precision = va_arg(args, int);
			if (flags->precision < 0)
				flags->precision_set = 0;
			(*i)++;
		}
		else if (ft_isdigit(format[*i]))
		{
			flags->precision = 0;
			while (ft_isdigit(format[*i]))
			{
				flags->precision = flags->precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
		else
			flags->precision = 0;
	}
}

void	parse_flags(const char *format, int *i, t_flags *flags, va_list args)
{
	parse_flag_chars(format, i, flags);
	parse_width(format, i, flags, args);
	parse_precision(format, i, flags, args);
}
