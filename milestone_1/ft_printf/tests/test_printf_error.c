/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:28:11 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 21:18:34 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	ret;

	printf("--- Testing printf error and edge cases ---\n\n");

	// Case 1: An invalid specifier ('%k') followed by a '%'
	// Most implementations print the invalid character 'k' and then the final '%'
	printf("1. Format string: \"%%k%%\"\n");
	fflush(stdout); // Ensure the line above prints before the test
	ret = printf("%k%");
	printf("\n   -> Return value: %d\n\n", ret);

	// Case 2: A regular character followed by a '%'
	// This is not an error. It prints 'o' and then handles the '%'
	// which is unterminated. Many systems just print the '%'.
	printf("2. Format string: \"o%%\"\n");
	fflush(stdout);
	ret = printf("o%");
	printf("\n   -> Return value: %d\n\n", ret);

	// Case 3: An unterminated '%' at the end of the string
	printf("3. Format string: \"Hello %%\"\n");
	fflush(stdout);
	ret = printf("Hello %");
	printf("\n   -> Return value: %d\n\n", ret);

	return (0);
}