%code requires {
    // New struct to hold comparison info
    typedef struct {
        int is_comparison; // Flag: 0=not a comparison, 1=is
        char var[32];      // Variable name (if simple comp)
        int op;            // 1=LT, 2=GT
        double val;        // Literal value
        int has_bitwise;   // 0=no, 1=yes.
    } CompInfo;
}

/* */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "checks.h"

extern int yylineno;
void yyerror(const char *s);
int yylex(void);

int return_seen = 0; // Flag for unreachable code
/* */
%}

%union {
    double num;
    char id[32];
    char* str_val;
    CompInfo comp_info; // This type is now defined via %code requires
}

%token <num> NUMBER
%token <id> ID
%token <str_val> STRING_LITERAL
%token INT FLOAT DOUBLE
%token RETURN PRINTF
%token DIV ASSIGN SEMI LPAREN RPAREN LBRACE RBRACE STAR COMMA
%token IF AND OR BIT_AND BIT_OR LT GT

/* --- Precedence Rules --- */
%left OR
%left AND
%left BIT_OR
%left BIT_AND
%nonassoc LT GT
%left DIV

%type <id> declaration assignment
%type <num> arg_list
%type <comp_info> expression

%%

program:
    statements
;

statements:
      /* empty */
    | statements statement
;

statement:
      simple_statement
    | block_statement
    | matched_if
    | unmatched_if
    | IF LPAREN expression RPAREN SEMI
      {
          if ($3.has_bitwise) check_bitwise_in_condition(yylineno);
          check_misplaced_semicolon(yylineno);
      }
    /* * --- THIS IS THE NEW ERROR RECOVERY RULE ---
     * 'error' is a special token. This rule means:
     * "If a syntax error is found, enter error mode.
     * Discard tokens until a SEMI is found. Then,
     * call yyerrok to exit error mode and resume parsing."
     */
    | error SEMI { yyerrok; }
;

simple_statement:
      declaration SEMI      { if(return_seen) check_unreachable(yylineno); }
    | assignment SEMI       { if(return_seen) check_unreachable(yylineno); }
    | return_statement      { if(return_seen) check_unreachable(yylineno); }
    | printf_statement SEMI { if(return_seen) check_unreachable(yylineno); }
;

block_statement:
      LBRACE statements RBRACE
;

matched_if:
      IF LPAREN expression RPAREN block_statement
      {
          if ($3.has_bitwise) check_bitwise_in_condition(yylineno);
      }
;

unmatched_if:
      IF LPAREN expression RPAREN simple_statement
      {
          if ($3.has_bitwise) check_bitwise_in_condition(yylineno);
          check_missing_braces(yylineno);
      }
    | IF LPAREN expression RPAREN matched_if
      {
          if ($3.has_bitwise) check_bitwise_in_condition(yylineno);
          check_missing_braces(yylineno);
      }
    | IF LPAREN expression RPAREN unmatched_if
      {
          if ($3.has_bitwise) check_bitwise_in_condition(yylineno);
          check_missing_braces(yylineno);
      }
;

/* --- FIXED DECLARATION RULE --- */
/* This now correctly includes all pointer types again */
declaration:
      INT ID                { add_var($2, 0, yylineno); }
    | FLOAT ID              { add_var($2, 0, yylineno); }
    | DOUBLE ID             { add_var($2, 0, yylineno); }
    | INT STAR ID           { add_var($3, 1, yylineno); }
    | FLOAT STAR ID         { add_var($3, 1, yylineno); }
    | DOUBLE STAR ID        { add_var($3, 1, yylineno); }
;

assignment:
      ID ASSIGN expression
      {
          check_undeclared($1, yylineno);
          set_initialized($1);
      }
    | STAR ID ASSIGN expression
      {
          check_segfault($2, yylineno);
      }
;

expression:
      NUMBER
      { $$.is_comparison = 0; $$.has_bitwise = 0; }
    | ID
      {
          check_undeclared($1, yylineno);
          check_uninitialized($1, yylineno);
          $$.is_comparison = 0; $$.has_bitwise = 0;
      }
    | expression DIV NUMBER
      {
          check_div_zero($3, yylineno);
          $$.is_comparison = 0;
          $$.has_bitwise = $1.has_bitwise;
      }
    | expression DIV ID
      {
          check_undeclared($3, yylineno);
          check_uninitialized($3, yylineno);
          check_div_zero(0, yylineno);
          $$.is_comparison = 0;
          $$.has_bitwise = $1.has_bitwise;
      }
    | ID LT NUMBER
      {
          $$.is_comparison = 1; strcpy($$.var, $1); $$.op = 1; $$.val = $3;
          $$.has_bitwise = 0;
      }
    | ID GT NUMBER
      {
          $$.is_comparison = 1; strcpy($$.var, $1); $$.op = 2; $$.val = $3;
          $$.has_bitwise = 0;
      }
    | expression AND expression
      {
          check_contradiction($1, $3, yylineno);
          $$.is_comparison = 0;
          $$.has_bitwise = $1.has_bitwise || $3.has_bitwise;
      }
    | expression OR expression
      {
          $$.is_comparison = 0;
          $$.has_bitwise = $1.has_bitwise || $3.has_bitwise;
      }
    | expression BIT_AND expression
      {
          $$.is_comparison = 0;
          $$.has_bitwise = 1; /* SET FLAG */
      }
    | expression BIT_OR expression
      {
          $$.is_comparison = 0;
          $$.has_bitwise = 1; /* SET FLAG */
      }
;

return_statement:
      RETURN expression SEMI { return_seen = 1; }
;

printf_statement:
      PRINTF LPAREN STRING_LITERAL RPAREN
      {
          check_printf($3, 0, yylineno); free($3);
      }
    | PRINTF LPAREN STRING_LITERAL COMMA arg_list RPAREN
      {
          check_printf($3, (int)$5, yylineno); free($3);
      }
;

arg_list:
      expression { $$ = 1; }
    | arg_list COMMA expression { $$ = $1 + 1; }
;

%%

void yyerror(const char *s) {
    /* We just print the error. The 'error' rule handles recovery. */
    //fprintf(stderr, "Syntax Error: %s at line %d\n", s, yylineno);
}

int main() {
  //  printf("--- 4-Member Modular C Runtime Checker (Extended) ---\n");
    yyparse();
   // printf("--- Check Complete ---\n");
    return 0;
}
