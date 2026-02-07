#include <stdio.h>
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 10: Misplaced semicolon after 'if'
void check_misplaced_semicolon(int lineno) {
    printf(RESET "Line %d: " PURPLE "[MISPLACED_SEMICOLON]" RESET " Misplaced semicolon after 'if'. The following code will always execute.\n", lineno);
}
