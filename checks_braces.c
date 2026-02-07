#include <stdio.h>
#include "checks.h"

#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 11: Missing braces on 'if' statement
void check_missing_braces(int lineno) {
    printf(RESET "Line %d: " PURPLE "[MISSING_BRACES]" RESET " 'if' statement without braces {}. This is risky and can lead to bugs.\n", lineno);
}
