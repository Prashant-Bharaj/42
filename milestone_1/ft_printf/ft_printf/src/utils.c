/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:38:05 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:38:12 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_count(char *str, int precision)
{
	int	len;
	int	i;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (precision >= 0 && precision < len)
		len = precision;
	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	print_padding(int count, int zero_flag)
{
	int		i;
	char	c;

	if (count <= 0)
		return (0);
	if (zero_flag)
		c = '0';
	else
		c = ' ';
	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		i++;
	}
	return (count);
}
