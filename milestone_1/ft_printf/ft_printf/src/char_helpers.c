/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:35:38 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:35:55 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_with_padding(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += putchar_count(c);
		count += print_padding(flags.width - 1, 0);
	}
	else
	{
		count += print_padding(flags.width - 1, 0);
		count += putchar_count(c);
	}
	return (count);
}

int	print_string_content(char *str, int str_len, int precision)
{
	if (str_len > 0)
		return (putstr_count(str, precision));
	return (0);
}

int	print_percent_left_padding(t_flags flags)
{
	if (flags.minus)
		return (0);
	if (flags.zero)
		return (print_padding(flags.width - 1, 1));
	return (print_padding(flags.width - 1, 0));
}
