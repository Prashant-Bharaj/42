/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_formatting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:37:11 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_prefix(int uppercase)
{
	if (uppercase)
		return (putstr_count("0X", -1));
	return (putstr_count("0x", -1));
}

int	print_precision_padding(t_flags flags, int str_len)
{
	if (flags.precision_set && flags.precision > str_len)
		return (print_padding(flags.precision - str_len, 1));
	return (0);
}

int	print_right_padding(t_flags flags, int width, int current_count)
{
	if (flags.minus)
		return (print_padding(width - current_count, 0));
	return (0);
}

int	print_left_padding(t_flags flags, int padding_width)
{
	if (flags.minus)
		return (0);
	return (print_padding(padding_width, should_use_zero_padding(flags)));
}
