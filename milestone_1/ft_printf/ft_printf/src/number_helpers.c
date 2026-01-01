/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:37:20 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:37:27 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int_sign(t_flags flags, int sign)
{
	if (sign)
		return (putchar_count('-'));
	if (flags.plus)
		return (putchar_count('+'));
	if (flags.space)
		return (putchar_count(' '));
	return (0);
}

int	calculate_int_precision(t_flags flags, int str_len)
{
	if (flags.precision_set && flags.precision > str_len)
		return (flags.precision);
	if (flags.precision_set && flags.precision == 0 && str_len == 0)
		return (0);
	return (str_len);
}

int	calculate_int_content_width(t_flags flags, int str_len, int sign)
{
	int	precision;
	int	content_width;

	precision = calculate_int_precision(flags, str_len);
	content_width = precision;
	if (flags.plus || flags.space || sign)
		content_width++;
	return (content_width);
}

int	print_int_left_padding(t_flags flags, int content_width, int sign)
{
	int	count;

	count = 0;
	if (flags.zero && !flags.precision_set)
	{
		count += print_int_sign(flags, sign);
		count += print_padding(flags.width - content_width, 1);
	}
	else
	{
		count += print_padding(flags.width - content_width, 0);
		count += print_int_sign(flags, sign);
	}
	return (count);
}

int	print_number_body(char *str, int str_len, t_flags flags)
{
	int	count;

	count = print_precision_padding(flags, str_len);
	if (str_len > 0)
		count += putstr_count(str, -1);
	return (count);
}
