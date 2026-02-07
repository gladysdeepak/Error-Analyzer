#include <stdio.h>
#include "symbol_table.h"
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 4: Use of undeclared variable
void check_undeclared(const char *var, int lineno) {
    if(var && !find_var(var)) {
        printf(RESET "Line %d: " PURPLE "[UNDECLARED_VARIABLE]" RESET " Undeclared variable '%s' used.\n", lineno, var);
    }
}
