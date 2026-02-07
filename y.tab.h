/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

    // New struct to hold comparison info
    typedef struct {
        int is_comparison; // Flag: 0=not a comparison, 1=is
        char var[32];      // Variable name (if simple comp)
        int op;            // 1=LT, 2=GT
        double val;        // Literal value
        int has_bitwise;   // 0=no, 1=yes.
    } CompInfo;

#line 60 "y.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    ID = 259,                      /* ID  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    DOUBLE = 263,                  /* DOUBLE  */
    RETURN = 264,                  /* RETURN  */
    PRINTF = 265,                  /* PRINTF  */
    DIV = 266,                     /* DIV  */
    ASSIGN = 267,                  /* ASSIGN  */
    SEMI = 268,                    /* SEMI  */
    LPAREN = 269,                  /* LPAREN  */
    RPAREN = 270,                  /* RPAREN  */
    LBRACE = 271,                  /* LBRACE  */
    RBRACE = 272,                  /* RBRACE  */
    STAR = 273,                    /* STAR  */
    COMMA = 274,                   /* COMMA  */
    IF = 275,                      /* IF  */
    AND = 276,                     /* AND  */
    OR = 277,                      /* OR  */
    BIT_AND = 278,                 /* BIT_AND  */
    BIT_OR = 279,                  /* BIT_OR  */
    LT = 280,                      /* LT  */
    GT = 281                       /* GT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define ID 259
#define STRING_LITERAL 260
#define INT 261
#define FLOAT 262
#define DOUBLE 263
#define RETURN 264
#define PRINTF 265
#define DIV 266
#define ASSIGN 267
#define SEMI 268
#define LPAREN 269
#define RPAREN 270
#define LBRACE 271
#define RBRACE 272
#define STAR 273
#define COMMA 274
#define IF 275
#define AND 276
#define OR 277
#define BIT_AND 278
#define BIT_OR 279
#define LT 280
#define GT 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    double num;
    char id[32];
    char* str_val;
    CompInfo comp_info; // This type is now defined via %code requires

#line 139 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
