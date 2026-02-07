/* */
%{
#include <string.h>
#include "y.tab.h"
extern int yylineno;
%}

%%

"int"           { return INT; /* */ }
"float"         { return FLOAT; /* */ }
"double"        { return DOUBLE; }
"return"        { return RETURN; }
"printf"        { return PRINTF; }
"if"            { return IF; }

[a-zA-Z_][a-zA-Z0-9_]* { strcpy(yylval.id, yytext); return ID; }
[0-9]+(\.[0-9]+)? { yylval.num = atof(yytext); return NUMBER; /* */ }

\"[^"]*\"       { yylval.str_val = strdup(yytext); return STRING_LITERAL; }

"/"             { return DIV; /* */ }
"="             { return ASSIGN; }
"*"             { return STAR; }
","             { return COMMA; }
";"             { return SEMI; /* */ }
"("             { return LPAREN; }
")"             { return RPAREN; /* */ }
"{"             { return LBRACE; /* */ }
"}"             { return RBRACE; /* */ }
"&&"            { return AND; }
"||"            { return OR; }
"&"             { return BIT_AND; }
"|"             { return BIT_OR; }
"<"             { return LT; }
">"             { return GT; }

\/\/[^\n]* ;   /* Ignore // comments */

\n              { yylineno++; /* */ }
[ \t]           ;   /* ignore spaces and tabs */
.               { return yytext[0]; /* */ }

%%

int yywrap() { return 1; }
