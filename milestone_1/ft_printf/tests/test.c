#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...)
{
    va_list args;
    int total = 0;
    
    va_start(args, count);  // Initialize with 'count' as last fixed arg
    
    for (int i = 0; i < count; i++)
    {
        int current = va_arg(args, int); 
        total += current;
        printf("Adding %d to total. Current total: %d\n", current, total);
    }
    
    va_end(args);  // Clean up
    return total;
}

#include <stdio.h>

void demonstrate_midway_copy(int count, ...)
{
    if (count == 0) return;

    va_list args_orig;
    va_list args_copy;

    va_start(args_orig, count);

    // --- Step 1: Consume the first argument from the original list ---
    int first_val = va_arg(args_orig, int);
    printf("Original list: Consumed first argument -> %d\n", first_val);

    // --- Step 2: Now, create a copy. It will copy the CURRENT state of args_orig ---
    printf("\n... Calling va_copy(args_copy, args_orig) ...\n\n");
    va_copy(args_copy, args_orig);

    // --- Step 3: Iterate through the COPIED list ---
    printf("Iterating through the COPIED list (starts from the 2nd arg):\n");
    for (int i = 1; i < count; i++) { // Loop from 1 since we skipped the first
        printf("  - Copied list value: %d\n", va_arg(args_copy, int));
    }
    va_end(args_copy); // Clean up the copy

    // --- Step 4: You can also continue iterating the ORIGINAL list ---
    printf("\nContinuing with the ORIGINAL list (also starts from the 2nd arg):\n");
    for (int i = 1; i < count; i++) {
        printf("  - Original list value: %d\n", va_arg(args_orig, int));
    }
    va_end(args_orig); // Clean up the original
}

int main() {
    printf("--- Demonstrating va_copy midway ---\n");
    demonstrate_midway_copy(5, 100, 200, 300, 400, 500);
    return 0;
}