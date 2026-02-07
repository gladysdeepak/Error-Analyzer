#include <stdio.h>
#include <string.h>
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 7: Printf format specifier mismatch
void check_printf(const char *format_str, int arg_count, int lineno) {
    int specifiers = 0;
    
    // Loop through format string, skipping first and last quote
    for (int i = 1; format_str[i] != '\0' && format_str[i+1] != '\0'; i++) {
        if (format_str[i] == '%') {
            if (format_str[i+1] == '%') {
                i++; // Skip '%%'
            } else if (strchr("dfsc", format_str[i+1])) { // Check for %d, %f, %s, %c
                specifiers++;
                i++;
            }
        }
    }

    if (specifiers != arg_count) {
        printf(RESET "Line %d: " PURPLE "[PRINTF_MISMATCH]" RESET " Mismatch in printf arguments. Expected %d, got %d.\n", lineno, specifiers, arg_count);
    }
}
