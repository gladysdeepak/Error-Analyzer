#include <stdio.h>
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 5: Unreachable code
void check_unreachable(int lineno) {
   // printf(RESET "Line %d: " PURPLE "[UNREACHABLE_CODE]" RESET " Code is unreachable.\n", lineno);
}
