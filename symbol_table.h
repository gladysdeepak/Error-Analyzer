#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_VARS 100

typedef struct {
    char name[32];
    int initialized;
    int is_pointer; // 0 = no, 1 = yes
} symbol;

extern symbol sym_table[MAX_VARS];
extern int sym_count;

// Function to find a variable, returns pointer or NULL
symbol* find_var(const char *name);

// Added lineno for error reporting and is_pointer for type
void add_var(const char *name, int is_pointer, int lineno);
void set_initialized(const char *name);
int is_initialized(const char *name);

#endif
