/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:37:02 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char specifier, va_list args, t_flags flags)
{
	if (specifier == '%')
		return (handle_percent(flags));
	else if (specifier == 'c')
		return (handle_char(args, flags));
	else if (specifier == 's')
		return (handle_string(args, flags));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_int(args, flags));
	else if (specifier == 'u')
		return (handle_unsigned(args, flags));
	else if (specifier == 'x')
		return (handle_hex(args, flags, 0));
	else if (specifier == 'X')
		return (handle_hex(args, flags, 1));
	else if (specifier == 'p')
		return (handle_pointer(args, flags));
	else
		return (0);
}

static int	process_format_spec(const char *format, int *i, va_list args)
{
	t_flags	flags;
	int		count;

	count = 0;
	(*i)++;
	flags = init_flags();
	parse_flags(format, i, &flags, args);
	if (format[*i])
	{
		count += handle_format(format[*i], args, flags);
		(*i)++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
			total_len += process_format_spec(format, &i, args);
		else
		{
			total_len += putchar_count(format[i]);
			i++;
		}
	}
	va_end(args);
	return (total_len);
}
