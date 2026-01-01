/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/09 00:37:52 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer_prefix_early(t_flags flags, int precision)
{
	int	count;

	count = putstr_count("0x", -1);
	count += print_padding(flags.width - precision - 2, 1);
	return (count);
}

int	print_pointer_prefix_late(t_flags flags)
{
	return (putstr_count("0x", -1));
}
