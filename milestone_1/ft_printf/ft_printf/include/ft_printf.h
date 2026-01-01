/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:47:18 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/08 15:19:26 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/**
 * @brief A struct to hold all parsed formatting flags for a specifier.
 *
 * @param minus      Left-justify the output ('-').
 * @param zero       Pad with zeros instead of spaces ('0').
 * @param width      Minimum field width.
 * @param precision  Precision for numbers or max length for strings ('.').
 * @param hash       Alternate form for hex/octal ('#').
 * @param space      Print a space before a positive number (' ').
 * @param plus       Print a '+' before a positive number ('+').
 */
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	precision;
	int	precision_set;
}	t_flags;

int		ft_printf(const char *format, ...);

t_flags	init_flags(void);
void	parse_flags(const char *format, int *i, t_flags *flags, va_list args);

int		handle_char(va_list args, t_flags flags);
int		handle_string(va_list args, t_flags flags);
int		handle_percent(t_flags flags);
int		handle_int(va_list args, t_flags flags);
int		handle_unsigned(va_list args, t_flags flags);
int		handle_hex(va_list args, t_flags flags, int uppercase);
int		handle_pointer(va_list args, t_flags flags);

int		putchar_count(char c);
int		putstr_count(char *str, int precision);
int		print_padding(int count, int zero_flag);
char	*ft_utoa_base(unsigned long long n, int base, int uppercase);

int		calculate_effective_str_len(int str_len, t_flags flags, int is_zero);
int		calculate_effective_precision(t_flags flags, int str_len);
int		should_use_zero_padding(t_flags flags);
int		calculate_left_padding_width(t_flags flags, int precision, int prefix_len);
int		print_hex_prefix(int uppercase);
int		print_precision_padding(t_flags flags, int str_len);
int		print_right_padding(t_flags flags, int width, int current_count);
int		print_left_padding(t_flags flags, int padding_width);
int		print_pointer_prefix_early(t_flags flags, int precision);
int		print_pointer_prefix_late(t_flags flags);
int		print_int_sign(t_flags flags, int sign);
int		calculate_int_precision(t_flags flags, int str_len);
int		calculate_int_content_width(t_flags flags, int str_len, int sign);
int		print_int_left_padding(t_flags flags, int content_width, int sign);
int		print_number_body(char *str, int str_len, t_flags flags);
int		get_string_precision(char *str, t_flags flags);
int		calculate_null_string_len(t_flags flags);
int		print_char_with_padding(char c, t_flags flags);
int		print_string_content(char *str, int str_len, int precision);
int		print_percent_left_padding(t_flags flags);
int		get_string_precision(char *str, t_flags flags);
int		calculate_null_string_len(t_flags flags);
int		extract_string_value(va_list args, char **str);
int		calculate_string_len(char *str, t_flags flags, int is_null);
int		print_string_left_padding(t_flags flags, int str_len);

#endif
