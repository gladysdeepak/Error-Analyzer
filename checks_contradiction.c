#include <stdio.h>
#include <string.h>
#include "checks.h"
#include "y.tab.h" // Add this include to get the CompInfo definition

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m" // Added PURPLE
#define RESET   "\033[0m"

// Check 8: Logical Contradiction
void check_contradiction(CompInfo c1, CompInfo c2, int lineno) {
    // We can only check if both sides are simple comparisons
    // e.g., (var < 10) AND (var > 20)
    if (!c1.is_comparison || !c2.is_comparison) {
        return;
    }

    // Check if they are comparing the same variable
    if (strcmp(c1.var, c2.var) != 0) {
        return;
    }

    // c1.op 1=LT, 2=GT
    // c2.op 1=LT, 2=GT

    int impossible = 0;

    // Case 1: (var < A) && (var > B)
    if (c1.op == 1 && c2.op == 2) {
        if (c1.val <= c2.val) { // (var < 10) && (var > 20)
            impossible = 1;
        }
    }
    // Case 2: (var > A) && (var < B)
    else if (c1.op == 2 && c2.op == 1) {
        if (c1.val >= c2.val) { // (var > 20) && (var < 10)
            impossible = 1;
        }
    }

    if (impossible) {
        printf(RESET "Line %d: " PURPLE "[LOGICAL_CONTRADICTION]" RESET " The 'if' condition can never be true.\n", lineno);
    }
}
