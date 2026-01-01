/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:36:43 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:36:52 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned_left_padding(t_flags flags, int precision)
{
	if (flags.minus)
		return (0);
	if (should_use_zero_padding(flags))
		return (print_padding(flags.width - precision, 1));
	return (print_padding(flags.width - precision, 0));
}

static int	print_unsigned_content(char *str, int str_len, t_flags flags)
{
	int	count;

	count = print_number_body(str, str_len, flags);
	return (count);
}

static int	print_unsigned_right_padding(t_flags flags, int count)
{
	return (print_right_padding(flags, flags.width, count));
}

static int	print_unsigned_formatted(char *str, int str_len, t_flags flags)
{
	int	count;
	int	precision;

	precision = calculate_effective_precision(flags, str_len);
	count = print_unsigned_left_padding(flags, precision);
	count += print_unsigned_content(str, str_len, flags);
	count += print_unsigned_right_padding(flags, count);
	return (count);
}

int	handle_unsigned(va_list args, t_flags flags)
{
	unsigned int	n;
	char			*str;
	int				str_len;
	int				count;

	n = va_arg(args, unsigned int);
	str = ft_utoa_base(n, 10, 0);
	if (!str)
		return (0);
	str_len = ft_strlen(str);
	str_len = calculate_effective_str_len(str_len, flags, (n == 0));
	count = print_unsigned_formatted(str, str_len, flags);
	free(str);
	return (count);
}
