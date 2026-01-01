/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:35:59 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:36:10 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list args, t_flags flags)
{
	char	c;

	c = va_arg(args, int);
	return (print_char_with_padding(c, flags));
}

static int	print_string_formatted(char *str, int str_len, t_flags flags,
		int precision)
{
	int	count;

	count = print_string_left_padding(flags, str_len);
	if (flags.minus)
	{
		count += print_string_content(str, str_len, precision);
		count += print_padding(flags.width - count, 0);
	}
	else
		count += print_string_content(str, str_len, precision);
	return (count);
}

int	handle_string(va_list args, t_flags flags)
{
	char	*str;
	int		str_len;
	int		precision;
	int		is_null;

	is_null = extract_string_value(args, &str);
	if (flags.precision_set)
		precision = flags.precision;
	else
		precision = -1;
	str_len = calculate_string_len(str, flags, is_null);
	return (print_string_formatted(str, str_len, flags, precision));
}

int	handle_percent(t_flags flags)
{
	int	count;

	count = print_percent_left_padding(flags);
	count += putchar_count('%');
	if (flags.minus)
		count += print_padding(flags.width - count, 0);
	return (count);
}
