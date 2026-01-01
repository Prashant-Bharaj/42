/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:38:16 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:38:23 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_base_len(unsigned long long n, int base)
{
	int					len;
	unsigned long long	temp;

	len = 1;
	temp = n;
	while (temp >= (unsigned long long)base)
	{
		temp /= base;
		len++;
	}
	return (len);
}

static char	*get_digit_string(int uppercase)
{
	if (uppercase)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static void	convert_number_to_string(char *str, unsigned long long n, int base,
		char *digits)
{
	int	len;

	len = calculate_base_len(n, base);
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	len--;
	while (n > 0)
	{
		str[len--] = digits[n % base];
		n /= base;
	}
}

char	*ft_utoa_base(unsigned long long n, int base, int uppercase)
{
	char	*str;
	char	*digits;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	digits = get_digit_string(uppercase);
	len = calculate_base_len(n, base);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	convert_number_to_string(str, n, base, digits);
	return (str);
}
