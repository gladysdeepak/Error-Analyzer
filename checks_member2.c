#include <stdio.h>
#include "symbol_table.h"
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

void check_uninitialized(const char *var, int lineno) {
    if(var && !is_initialized(var)) {
        printf(RESET "Line %d: " PURPLE "[UNINITIALIZED_USE]" RESET " Uninitialized variable '%s' used.\n", lineno, var);
    }
}
