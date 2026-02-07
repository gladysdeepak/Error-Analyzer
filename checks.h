#ifndef CHECKS_H
#define CHECKS_H

#include "y.tab.h"

// Existing
void check_div_zero(double value, int lineno);
void check_uninitialized(const char *var, int lineno);
void check_redeclaration(const char *var, int lineno);
void check_undeclared(const char *var, int lineno);
void check_unreachable(int lineno);
void check_segfault(const char *var, int lineno);
void check_printf(const char *format_str, int arg_count, int lineno);
void check_contradiction(CompInfo c1, CompInfo c2, int lineno);

// --- New Function Prototypes ---
void check_bitwise_in_condition(int lineno);
void check_misplaced_semicolon(int lineno);
void check_missing_braces(int lineno);

#endif
