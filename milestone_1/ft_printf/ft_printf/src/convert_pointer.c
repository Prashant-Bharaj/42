/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:36:38 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	extract_pointer(va_list args)
{
	return ((unsigned long long)va_arg(args, void *));
}

static int	print_null_pointer(t_flags flags)
{
	int	str_len;
	int	precision;
	int	count;

	str_len = 5;
	str_len = calculate_effective_str_len(str_len, flags, 0);
	precision = calculate_effective_precision(flags, str_len);
	count = print_left_padding(flags, calculate_left_padding_width(flags,
				precision, 0));
	if (str_len > 0)
		count += putstr_count("(nil)", -1);
	count += print_right_padding(flags, flags.width, count);
	return (count);
}

static int	print_pointer_with_formatting(char *str, int str_len, t_flags flags)
{
	int	count;
	int	precision;
	int	padding_width;

	precision = calculate_effective_precision(flags, str_len);
	count = 0;
	if (!flags.minus)
	{
		padding_width = calculate_left_padding_width(flags, precision, 2);
		if (should_use_zero_padding(flags))
			count += print_pointer_prefix_early(flags, precision);
		else
			count += print_left_padding(flags, padding_width);
	}
	if (flags.minus || !should_use_zero_padding(flags))
		count += print_pointer_prefix_late(flags);
	count += print_precision_padding(flags, str_len);
	if (str_len > 0)
		count += putstr_count(str, -1);
	count += print_right_padding(flags, flags.width, count);
	return (count);
}

int	handle_pointer(va_list args, t_flags flags)
{
	unsigned long long	ptr;
	char				*str;
	int					str_len;
	int					count;

	ptr = extract_pointer(args);
	if (ptr == 0)
		return (print_null_pointer(flags));
	str = ft_utoa_base(ptr, 16, 0);
	if (!str)
		return (0);
	str_len = ft_strlen(str);
	str_len = calculate_effective_str_len(str_len, flags, (ptr == 0));
	count = print_pointer_with_formatting(str, str_len, flags);
	free(str);
	return (count);
}
