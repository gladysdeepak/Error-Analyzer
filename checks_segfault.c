#include <stdio.h>
#include "symbol_table.h"
#include "checks.h"

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 6: Segmentation fault (generic)
void check_segfault(const char *var, int lineno) {
    symbol* s = find_var(var);
    
    if (s) {
        if (!s->is_pointer) {
             printf(RESET "Line %d: " PURPLE "[DEREF_NON_POINTER]" RESET " Cannot dereference non-pointer variable '%s'.\n", lineno, var);
        } else if (!s->initialized) {
             printf(RESET "Line %d: " PURPLE "[SEGMENTATION_FAULT]" RESET " Dereferencing uninitialized pointer '%s'.\n", lineno, var);
        }
        // If s is a pointer AND initialized, it's considered valid in this simple check.
    }
    // If !s, check_undeclared() will be called from the parser, so no need to repeat.
}
