int a;
float a;  // Error: Re-declaration

int b;
b = 10;
c = 20;   // Error: Undeclared

int *p;
*p = 5;   // Error: Segfault

int d;
d = b / 0; // Error: Div by zero

int e;
int f;
f = e;    // Warning: Uninitialized

printf("%d %f %s", 10, 20.5); // Warning: Printf mismatch

if (b < 5 && b > 50) { } // Warning: Logical contradiction


if (b & 1) { } // Warning: Bitwise operator in 'if'

if (b > 0);    // Error: Misplaced semicolon
    a = 1;     // This will always run

if (b > 5)     // Warning: Missing braces
    b = 1;
    a = 2;     // This 'a = 2' is NOT part of the if.
                
return 0;

a = 10;   // Warning: Unreachable
b = 20;   // Warning: Unreachable





