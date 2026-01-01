/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:00:00 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 23:00:00 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf/include/libftprintf.h"

void	print_separator(void)
{
	printf("\n");
	printf("============================================================\n");
	printf("\n");
}

void	test_minus_flag(void)
{
	printf("=== FLAG: '-' (MINUS) - Left-justify output ===\n\n");
	printf("Without '-': Right-aligned (default)\n");
	printf("Format: \"%%10d\" with value 42\n");
	printf("Result: [");
	ft_printf("%10d", 42);
	printf("]\n\n");
	
	printf("With '-': Left-aligned\n");
	printf("Format: \"%%-10d\" with value 42\n");
	printf("Result: [");
	ft_printf("%-10d", 42);
	printf("]\n\n");
	
	printf("Note: When '-' is used, '0' flag is ignored\n");
	printf("Format: \"%%-010d\" with value 42\n");
	printf("Result: [");
	ft_printf("%-010d", 42);
	printf("]\n\n");
}

void	test_zero_flag(void)
{
	printf("=== FLAG: '0' (ZERO) - Pad with zeros ===\n\n");
	printf("Without '0': Pad with spaces (default)\n");
	printf("Format: \"%%10d\" with value 42\n");
	printf("Result: [");
	ft_printf("%10d", 42);
	printf("]\n\n");
	
	printf("With '0': Pad with zeros\n");
	printf("Format: \"%%010d\" with value 42\n");
	printf("Result: [");
	ft_printf("%010d", 42);
	printf("]\n\n");
	
	printf("Note: '0' is ignored when '-' is present\n");
	printf("Format: \"%%-010d\" with value 42\n");
	printf("Result: [");
	ft_printf("%-010d", 42);
	printf("]\n\n");
	
	printf("Note: '0' is ignored when precision is set\n");
	printf("Format: \"%%010.5d\" with value 42\n");
	printf("Result: [");
	ft_printf("%010.5d", 42);
	printf("]\n\n");
}

void	test_hash_flag(void)
{
	printf("=== FLAG: '#' (HASH) - Alternate form ===\n\n");
	printf("For hex numbers (x/X): Adds '0x' or '0X' prefix\n");
	printf("Without '#': \"%%x\" with value 255\n");
	printf("Result: ");
	ft_printf("%x", 255);
	printf("\n\n");
	
	printf("With '#': \"%%#x\" with value 255\n");
	printf("Result: ");
	ft_printf("%#x", 255);
	printf("\n\n");
	
	printf("Uppercase: \"%%#X\" with value 255\n");
	printf("Result: ");
	ft_printf("%#X", 255);
	printf("\n\n");
	
	printf("With zero: \"%%#x\" with value 0\n");
	printf("Result: ");
	ft_printf("%#x", 0);
	printf("\n\n");
}

void	test_plus_flag(void)
{
	printf("=== FLAG: '+' (PLUS) - Show sign for positive numbers ===\n\n");
	printf("Without '+': No sign for positive numbers\n");
	printf("Format: \"%%d\" with value 42\n");
	printf("Result: ");
	ft_printf("%d", 42);
	printf("\n\n");
	
	printf("With '+': Show '+' for positive numbers\n");
	printf("Format: \"%%+d\" with value 42\n");
	printf("Result: ");
	ft_printf("%+d", 42);
	printf("\n\n");
	
	printf("Negative numbers always show '-'\n");
	printf("Format: \"%%+d\" with value -42\n");
	printf("Result: ");
	ft_printf("%+d", -42);
	printf("\n\n");
	
	printf("Note: '+' takes precedence over ' ' (space)\n");
	printf("Format: \"%%+ d\" with value 42\n");
	printf("Result: ");
	ft_printf("%+ d", 42);
	printf("\n\n");
}

void	test_space_flag(void)
{
	printf("=== FLAG: ' ' (SPACE) - Print space before positive numbers ===\n\n");
	printf("Without ' ': No space before positive numbers\n");
	printf("Format: \"%%d\" with value 42\n");
	printf("Result: [");
	ft_printf("%d", 42);
	printf("]\n\n");
	
	printf("With ' ': Space before positive numbers\n");
	printf("Format: \"%% d\" with value 42\n");
	printf("Result: [");
	ft_printf("% d", 42);
	printf("]\n\n");
	
	printf("Negative numbers: No extra space (they have '-')\n");
	printf("Format: \"%% d\" with value -42\n");
	printf("Result: [");
	ft_printf("% d", -42);
	printf("]\n\n");
	
	printf("Note: ' ' is ignored when '+' is present\n");
	printf("Format: \"%%+ d\" with value 42\n");
	printf("Result: [");
	ft_printf("%+ d", 42);
	printf("]\n\n");
}

void	test_width(void)
{
	printf("=== WIDTH - Minimum field width ===\n\n");
	printf("No width: \"%%d\" with value 42\n");
	printf("Result: [");
	ft_printf("%d", 42);
	printf("]\n\n");
	
	printf("Width 10: \"%%10d\" with value 42\n");
	printf("Result: [");
	ft_printf("%10d", 42);
	printf("]\n\n");
	
	printf("Width with '*': \"%%*d\" with width=10, value=42\n");
	printf("Result: [");
	ft_printf("%*d", 10, 42);
	printf("]\n\n");
	
	printf("Negative width becomes '-' flag: \"%%*d\" with width=-10, value=42\n");
	printf("Result: [");
	ft_printf("%*d", -10, 42);
	printf("]\n\n");
	
	printf("Width with string: \"%%10s\" with \"hello\"\n");
	printf("Result: [");
	ft_printf("%10s", "hello");
	printf("]\n\n");
}

void	test_precision(void)
{
	printf("=== PRECISION - Control number of digits or string length ===\n\n");
	
	printf("For integers:\n");
	printf("No precision: \"%%d\" with value 42\n");
	printf("Result: ");
	ft_printf("%d", 42);
	printf("\n\n");
	
	printf("Precision 5: \"%%.5d\" with value 42 (pads with zeros)\n");
	printf("Result: ");
	ft_printf("%.5d", 42);
	printf("\n\n");
	
	printf("Precision 1: \"%%.1d\" with value 42\n");
	printf("Result: ");
	ft_printf("%.1d", 42);
	printf("\n\n");
	
	printf("Precision 0: \"%%.0d\" with value 0 (may print nothing)\n");
	printf("Result: ");
	ft_printf("%.0d", 0);
	printf("\n\n");
	
	printf("For strings:\n");
	printf("No precision: \"%%s\" with \"hello\"\n");
	printf("Result: ");
	ft_printf("%s", "hello");
	printf("\n\n");
	
	printf("Precision 3: \"%%.3s\" with \"hello\" (truncates to 3 chars)\n");
	printf("Result: ");
	ft_printf("%.3s", "hello");
	printf("\n\n");
	
	printf("Precision with '*': \"%%.*s\" with precision=3, \"hello\"\n");
	printf("Result: ");
	ft_printf("%.*s", 3, "hello");
	printf("\n\n");
	
	printf("Negative precision is ignored: \"%%.*s\" with precision=-1, \"hello\"\n");
	printf("Result: ");
	ft_printf("%.*s", -1, "hello");
	printf("\n\n");
}

void	test_combined_flags(void)
{
	printf("=== COMBINED FLAGS - Multiple flags together ===\n\n");
	
	printf("Width + Precision: \"%%10.5d\" with value 42\n");
	printf("Result: [");
	ft_printf("%10.5d", 42);
	printf("]\n\n");
	
	printf("Minus + Width: \"%%-10d\" with value 42\n");
	printf("Result: [");
	ft_printf("%-10d", 42);
	printf("]\n\n");
	
	printf("Plus + Width: \"%%+10d\" with value 42\n");
	printf("Result: [");
	ft_printf("%+10d", 42);
	printf("]\n\n");
	
	printf("Zero + Width: \"%%010d\" with value 42\n");
	printf("Result: [");
	ft_printf("%010d", 42);
	printf("]\n\n");
	
	printf("Hash + Width + Hex: \"%%#10x\" with value 255\n");
	printf("Result: [");
	ft_printf("%#10x", 255);
	printf("]\n\n");
	
	printf("Minus + Plus + Width: \"%%-+10d\" with value 42\n");
	printf("Result: [");
	ft_printf("%-+10d", 42);
	printf("]\n\n");
	
	printf("Space + Width: \"%% 10d\" with value 42\n");
	printf("Result: [");
	ft_printf("% 10d", 42);
	printf("]\n\n");
	
	printf("Complex: \"%%-+10.5d\" with value 42\n");
	printf("Result: [");
	ft_printf("%-+10.5d", 42);
	printf("]\n\n");
}

void	test_different_specifiers(void)
{
	printf("=== FLAGS WITH DIFFERENT SPECIFIERS ===\n\n");
	
	printf("Character (c):\n");
	printf("Width 10: \"%%10c\" with 'A'\n");
	printf("Result: [");
	ft_printf("%10c", 'A');
	printf("]\n\n");
	
	printf("String (s):\n");
	printf("Width 10: \"%%10s\" with \"hello\"\n");
	printf("Result: [");
	ft_printf("%10s", "hello");
	printf("]\n\n");
	
	printf("Precision 3: \"%%.3s\" with \"hello\"\n");
	printf("Result: [");
	ft_printf("%.3s", "hello");
	printf("]\n\n");
	
	printf("Unsigned (u):\n");
	printf("Width 10: \"%%10u\" with 42\n");
	printf("Result: [");
	ft_printf("%10u", 42);
	printf("]\n\n");
	
	printf("Precision 5: \"%%.5u\" with 42\n");
	printf("Result: [");
	ft_printf("%.5u", 42);
	printf("]\n\n");
	
	printf("Pointer (p):\n");
	int num = 42;
	printf("Width 20: \"%%20p\" with &num\n");
	printf("Result: [");
	ft_printf("%20p", &num);
	printf("]\n\n");
}

int	main(void)
{
	printf("╔══════════════════════════════════════════════════════════╗\n");
	printf("║     FT_PRINTF FLAGS EXPLANATION AND TEST PROGRAM         ║\n");
	printf("╚══════════════════════════════════════════════════════════╝\n");
	
	print_separator();
	test_minus_flag();
	print_separator();
	test_zero_flag();
	print_separator();
	test_hash_flag();
	print_separator();
	test_plus_flag();
	print_separator();
	test_space_flag();
	print_separator();
	test_width();
	print_separator();
	test_precision();
	print_separator();
	test_combined_flags();
	print_separator();
	test_different_specifiers();
	print_separator();
	
	printf("=== SUMMARY ===\n\n");
	printf("Flags available:\n");
	printf("  '-'  : Left-justify (overrides '0')\n");
	printf("  '0'  : Pad with zeros (ignored with '-' or precision)\n");
	printf("  '#'  : Alternate form (0x/0X for hex)\n");
	printf("  '+'  : Show + for positive numbers\n");
	printf("  ' '  : Show space for positive numbers (ignored with '+')\n");
	printf("\n");
	printf("Width:\n");
	printf("  Number: Minimum field width (e.g., %%10d)\n");
	printf("  '*'   : Width from argument (e.g., %%*d)\n");
	printf("\n");
	printf("Precision:\n");
	printf("  '.number' : Precision value (e.g., %%.5d)\n");
	printf("  '.*'      : Precision from argument (e.g., %%.*d)\n");
	printf("\n");
	printf("Flag priority:\n");
	printf("  1. '-' overrides '0'\n");
	printf("  2. '+' overrides ' '\n");
	printf("  3. Precision overrides '0' for numbers\n");
	printf("\n");
	
	return (0);
}

