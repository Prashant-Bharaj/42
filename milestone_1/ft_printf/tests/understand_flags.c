/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understand_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:00:00 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 23:00:00 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int		num = 4212;
	int		neg_num = -42;
	char	*str = "hello";
	unsigned int hex_num = 255;

	printf("╔══════════════════════════════════════════════════════════╗\n");
	printf("║          UNDERSTANDING PRINTF FLAGS                      ║\n");
	printf("╚══════════════════════════════════════════════════════════╝\n\n");

	// /* ========== FLAG: '-' (MINUS) - Left-justify ========== */
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	// printf("FLAG: '-' (MINUS) - Left-justify output\n");
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	// printf("Without '-': Right-aligned (default)\n");
	// printf("Format: \"%%10d\" with value %d\n", num);
	// printf("Output: [%10d]\n", num);
    // printf("with less number: [%3d]\n\n", num);

	// printf("With '-': Left-aligned\n");
	// printf("Format: \"%%-10d\" with value %d\n", num);
	// printf("Output: [%-10d]\n\n", num);

	// /* ========== FLAG: '0' (ZERO) - Pad with zeros ========== */
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	// printf("FLAG: '0' (ZERO) - Pad with zeros instead of spaces\n");
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	// printf("Without '0': Pad with spaces (default)\n");
	// printf("Format: \"%%10d\" with value %d\n", num);
	// printf("Output: [%10d]\n\n", num);

	printf("With '0': Pad with zeros\n");
	printf("Format: \"%%010d\" with value %d\n", num);
	printf("Output: [%010d]\n\n", num);

	printf("Note: '0' is ignored when '-' is present\n");
	printf("Format: \"%%-010d\" with value %d\n", num);
	printf("Output: [%-010d]\n\n", num);

	/* ========== FLAG: '#' (HASH) - Alternate form ========== */
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("FLAG: '#' (HASH) - Alternate form (adds 0x/0X for hex)\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	printf("Without '#': Normal hex output\n");
	printf("Format: \"%%x\" with value %d\n", hex_num);
	printf("Output: %x\n\n", hex_num);

	printf("With '#': Adds '0x' prefix\n");
	printf("Format: \"%%#x\" with value %d\n", hex_num);
	printf("Output: %#x\n\n", hex_num);

	printf("Uppercase with '#': Adds '0X' prefix\n");
	printf("Format: \"%%#X\" with value %d\n", hex_num);
	printf("Output: %#X\n\n", hex_num);

	/* ========== FLAG: '+' (PLUS) - Show + for positive ========== */
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("FLAG: '+' (PLUS) - Show '+' sign for positive numbers\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	printf("Without '+': No sign for positive numbers\n");
	printf("Format: \"%%d\" with value %d\n", num);
	printf("Output: %d\n\n", num);

	printf("With '+': Shows '+' for positive numbers\n");
	printf("Format: \"%%+d\" with value %d\n", num);
	printf("Output: %+d\n\n", num);

	printf("Negative numbers always show '-'\n");
	printf("Format: \"%%+d\" with value %d\n", neg_num);
	printf("Output: %+d\n\n", neg_num);

	/* ========== FLAG: ' ' (SPACE) - Space before positive ========== */
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("FLAG: ' ' (SPACE) - Print space before positive numbers\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	printf("Without ' ': No space before positive numbers\n");
	printf("Format: \"%%d\" with value %d\n", num);
	printf("Output: [%d]\n\n", num);

	printf("With ' ': Space before positive numbers\n");
	printf("Format: \"%% d\" with value %d\n", num);
	printf("Output: [% d]\n\n", num);

	printf("Negative numbers: No extra space (they have '-')\n");
	printf("Format: \"%% d\" with value %d\n", neg_num);
	printf("Output: [% d]\n\n", neg_num);

	printf("Note: ' ' is ignored when '+' is present\n");
	printf("Format: \"%%+ d\" with value %d\n", num);
	printf("Output: [%+ d]\n\n", num);

	/* ========== WIDTH ========== */
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("WIDTH - Minimum field width\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	printf("No width: \"%%d\" with value %d\n", num);
	printf("Output: [%d]\n\n", num);

	printf("Width 10: \"%%10d\" with value %d\n", num);
	printf("Output: [%10d]\n\n", num);

	printf("Width with '*': \"%%*d\" with width=10, value=%d\n", num);
	printf("Output: [%*d]\n\n", 10, num);

	printf("Width with string: \"%%10s\" with \"%s\"\n", str);
	printf("Output: [%10s]\n\n", str);

	// /* ========== PRECISION ========== */
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	// printf("PRECISION - Control digits or string length\n");
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	// printf("For integers:\n");
	// printf("No precision: \"%%d\" with value %d\n", num);
	// printf("Output: %d\n\n", num);

	// printf("Precision 5: \"%%.5d\" with value %d (pads with zeros)\n", num);
	// printf("Output: %.5d\n\n", num);

	// printf("Precision 1: \"%%.1d\" with value %d\n", num);
	// printf("Output: %.1d\n\n", num);

	// printf("For strings:\n");
	// printf("No precision: \"%%s\" with \"%s\"\n", str);
	// printf("Output: %s\n\n", str);

	// printf("Precision 3: \"%%.3s\" with \"%s\" (truncates to 3 chars)\n", str);
	// printf("Output: %.3s\n\n", str);

	// printf("Precision with '*': \"%%.*s\" with precision=3, \"%s\"\n", str);
	// printf("Output: %.*s\n\n", 3, str);

	// /* ========== COMBINED FLAGS ========== */
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	// printf("COMBINED FLAGS - Multiple flags together\n");
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	// printf("Width + Precision: \"%%10.5d\" with value %d\n", num);
	// printf("Output: [%10.5d]\n\n", num);

	// printf("Minus + Width: \"%%-10d\" with value %d\n", num);
	// printf("Output: [%-10d]\n\n", num);

	// printf("Plus + Width: \"%%+10d\" with value %d\n", num);
	// printf("Output: [%+10d]\n\n", num);

	// printf("Zero + Width: \"%%010d\" with value %d\n", num);
	// printf("Output: [%010d]\n\n", num);

	// printf("Hash + Width + Hex: \"%%#10x\" with value %d\n", hex_num);
	// printf("Output: [%#10x]\n\n", hex_num);

	// printf("Minus + Plus + Width: \"%%-+10d\" with value %d\n", num);
	// printf("Output: [%-+10d]\n\n", num);

	// /* ========== SUMMARY ========== */
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	// printf("SUMMARY\n");
	// printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

	// printf("Flags:\n");
	// printf("  '-'  : Left-justify (overrides '0')\n");
	// printf("  '0'  : Pad with zeros (ignored with '-' or precision)\n");
	// printf("  '#'  : Alternate form (0x/0X for hex)\n");
	// printf("  '+'  : Show + for positive numbers\n");
	// printf("  ' '  : Show space for positive numbers (ignored with '+')\n");
	// printf("\n");
	// printf("Width: Minimum field width (number or *)\n");
	// printf("Precision: Control digits/string length (.number or .*)\n");
	// printf("\n");
	// printf("Flag Priority:\n");
	// printf("  1. '-' overrides '0'\n");
	// printf("  2. '+' overrides ' '\n");
	// printf("  3. Precision overrides '0' for numbers\n");

	return (0);
}

