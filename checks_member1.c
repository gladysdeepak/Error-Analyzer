#include <stdio.h>
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

void check_div_zero(double value, int lineno) {
    if(value == 0) {
        printf(RESET "Line %d: " PURPLE "[DIVISION_BY_ZERO]" RESET " Division by zero detected.\n", lineno);
    }
}
