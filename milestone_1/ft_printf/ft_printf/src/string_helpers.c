/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:37:58 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_string_precision(char *str, t_flags flags)
{
	int	str_len;
	int	precision;

	if (flags.precision_set)
		precision = flags.precision;
	else
		precision = -1;
	str_len = ft_strlen(str);
	if (precision >= 0 && precision < str_len)
		str_len = precision;
	return (str_len);
}

int	calculate_null_string_len(t_flags flags)
{
	if (flags.precision_set && flags.precision >= 6)
		return (6);
	if (flags.precision_set)
		return (0);
	return (6);
}

int	extract_string_value(va_list args, char **str)
{
	int	is_null;

	*str = va_arg(args, char *);
	is_null = (*str == NULL);
	if (!*str)
		*str = "(null)";
	return (is_null);
}

int	calculate_string_len(char *str, t_flags flags, int is_null)
{
	if (is_null)
		return (calculate_null_string_len(flags));
	return (get_string_precision(str, flags));
}

int	print_string_left_padding(t_flags flags, int str_len)
{
	if (flags.minus)
		return (0);
	return (print_padding(flags.width - str_len, 0));
}
