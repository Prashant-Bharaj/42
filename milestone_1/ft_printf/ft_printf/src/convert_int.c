/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:36:32 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*extract_int_str(int n, int *sign)
{
	char	*str;
	char	*temp;

	str = ft_itoa(n);
	if (!str)
		return (NULL);
	if (str[0] == '-')
		*sign = 1;
	else
		*sign = 0;
	if (*sign)
	{
		temp = str;
		str = ft_strdup(str + 1);
		free(temp);
	}
	return (str);
}

static int	print_int_left_part(t_flags flags, int str_len, int sign)
{
	int	content_width;

	content_width = calculate_int_content_width(flags, str_len, sign);
	if (flags.minus)
		return (print_int_sign(flags, sign));
	return (print_int_left_padding(flags, content_width, sign));
}

static int	print_int_right_part(t_flags flags, int count)
{
	if (flags.minus)
		return (print_right_padding(flags, flags.width, count));
	return (0);
}

static int	print_int_formatted(char *str, int str_len, t_flags flags, int sign)
{
	int	count;

	count = print_int_left_part(flags, str_len, sign);
	count += print_number_body(str, str_len, flags);
	count += print_int_right_part(flags, count);
	return (count);
}

int	handle_int(va_list args, t_flags flags)
{
	int		n;
	char	*str;
	int		str_len;
	int		sign;
	int		count;

	n = va_arg(args, int);
	str = extract_int_str(n, &sign);
	if (!str)
		return (0);
	str_len = ft_strlen(str);
	str_len = calculate_effective_str_len(str_len, flags, (n == 0));
	count = print_int_formatted(str, str_len, flags, sign);
	free(str);
	return (count);
}
