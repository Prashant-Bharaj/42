/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:37:07 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calculate_effective_str_len(int str_len, t_flags flags, int is_zero)
{
	if (flags.precision_set && flags.precision == 0 && is_zero)
		return (0);
	return (str_len);
}

int	calculate_effective_precision(t_flags flags, int str_len)
{
	if (flags.precision_set && flags.precision > str_len)
		return (flags.precision);
	return (str_len);
}

int	should_use_zero_padding(t_flags flags)
{
	if (flags.zero && !flags.precision_set)
		return (1);
	return (0);
}

int	calculate_left_padding_width(t_flags flags, int precision, int prefix_len)
{
	if (flags.minus)
		return (0);
	return (flags.width - precision - prefix_len);
}
