# 
CC = gcc
LEX = lex
YACC = yacc

all: checker

checker: lex.yy.c y.tab.c symbol_table.c checks_member1.c checks_member2.c checks_member3.c checks_member4.c checks_unreachable.c checks_segfault.c checks_printf.c checks_contradiction.c checks_bitwise.c checks_semicolon.c checks_braces.c
	$(CC) lex.yy.c y.tab.c symbol_table.c checks_member1.c checks_member2.c checks_member3.c checks_member4.c checks_unreachable.c checks_segfault.c checks_printf.c checks_contradiction.c checks_bitwise.c checks_semicolon.c checks_braces.c -o checker -lm

lex.yy.c: lexer.l
	$(LEX) lexer.l

y.tab.c: parser.y
	$(YACC) -d parser.y

run: checker
	./checker < test.c

clean:
	rm -f lex.yy.c y.tab.c y.tab.h checker *.o
