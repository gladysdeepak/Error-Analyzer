#include <stdio.h>
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 3: Re-declaration of variables
void check_redeclaration(const char *var, int lineno) {
    printf(RESET "Line %d: " PURPLE "[REDECLARATION_ERROR]" RESET " Re-declaration of variable '%s'.\n", lineno, var);
}
