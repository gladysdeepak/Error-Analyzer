#include <stdio.h>
#include "checks.h"

#define PURPLE  "\033[1;35m"
#define RESET "\033[0m"


// Check 9: Bitwise operator in a logical condition
void check_bitwise_in_condition(int lineno) {
    printf(RESET "Line %d: " PURPLE "[BITWISE_WARNING]" RESET " Bitwise operator ('&' or '|') used in 'if' condition... "
           "Did you mean '&&' or '||'?\n",lineno);
}
