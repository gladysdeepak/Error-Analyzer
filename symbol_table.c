#include <string.h>
#include <stdio.h> // for NULL
#include "symbol_table.h"
#include "checks.h" // For check_redeclaration

symbol sym_table[MAX_VARS];
int sym_count = 0;

symbol* find_var(const char *name) {
    for(int i = 0; i < sym_count; i++) {
        if(strcmp(sym_table[i].name, name) == 0) {
            return &sym_table[i];
        }
    }
    return NULL;
}

void add_var(const char *name, int is_pointer, int lineno) {
    // Check for re-declaration
    if(find_var(name) != NULL) {
        check_redeclaration(name, lineno);
        return;
    }

    // Add new variable
    if(sym_count < MAX_VARS) {
        strcpy(sym_table[sym_count].name, name);
        sym_table[sym_count].initialized = 0;
        sym_table[sym_count].is_pointer = is_pointer;
        sym_count++;
    } else {
        // Handle symbol table overflow if necessary
    }
}

void set_initialized(const char *name) {
    symbol* s = find_var(name);
    if(s) {
        s->initialized = 1;
    }
    // If s is NULL, check_undeclared() in parser should have caught it.
}

int is_initialized(const char *name) {
    symbol* s = find_var(name);
    if(s) {
        return s->initialized;
    }
    return 0; // undeclared treated as uninitialized
}
