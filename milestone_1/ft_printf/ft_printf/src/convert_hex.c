/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:36:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:36:24 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*extract_hex_str(va_list args, int uppercase, unsigned int *n)
{
	char	*str;

	*n = va_arg(args, unsigned int);
	str = ft_utoa_base(*n, 16, uppercase);
	return (str);
}

static int	calculate_hex_prefix_len(t_flags flags, unsigned int n)
{
	if (flags.hash && n != 0)
		return (2);
	return (0);
}

static int	print_hex_left_part(t_flags flags, int precision, int prefix_len,
		int uppercase)
{
	int	count;
	int	padding_width;

	padding_width = calculate_left_padding_width(flags, precision, prefix_len);
	count = print_left_padding(flags, padding_width);
	if (prefix_len > 0)
		count += print_hex_prefix(uppercase);
	return (count);
}

static int	print_hex_formatted_content(char *str, int str_len, t_flags flags,
		int count)
{
	count += print_precision_padding(flags, str_len);
	if (str_len > 0)
		count += putstr_count(str, -1);
	count += print_right_padding(flags, flags.width, count);
	return (count);
}

int	handle_hex(va_list args, t_flags flags, int uppercase)
{
	unsigned int	n;
	char			*str;
	int				str_len;
	int				count;

	str = extract_hex_str(args, uppercase, &n);
	if (!str)
		return (0);
	str_len = ft_strlen(str);
	str_len = calculate_effective_str_len(str_len, flags, (n == 0));
	count = print_hex_left_part(flags, calculate_effective_precision(flags,
				str_len), calculate_hex_prefix_len(flags, n), uppercase);
	count = print_hex_formatted_content(str, str_len, flags, count);
	free(str);
	return (count);
}
