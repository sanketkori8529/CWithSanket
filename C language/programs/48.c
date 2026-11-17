//Program to show the working of relational operators, logical operator and increment/decrement operator.


#include <stdio.h>

int main() {
    int a,b;

    printf("Enter first number and second number: ");
    scanf("%d %d",&a,&b);

    // 1. RELATIONAL OPERATORS (Return 1 for True, 0 for False)
    printf("=== RELATIONAL OPERATORS (a = %d, b = %d) ===\n", a, b);
    printf("a == b : %d\n", a == b);   // Equal to
    printf("a != b : %d\n", a != b);   // Not equal to
    printf("a > b  : %d\n", a > b);    // Greater than
    printf("a < b  : %d\n", a < b);    // Less than
    printf("a >= b : %d\n", a >= b);   // Greater than or equal to
    printf("a <= b : %d\n\n", a <= b); // Less than or equal to

    // 2. LOGICAL OPERATORS (Return 1 for True, 0 for False)
    printf("=== LOGICAL OPERATORS ===\n");
    printf("(a > b) && (b > 0) : %d\n", (a > b) && (b > 0)); // Logical AND
    printf("(a < b) || (b > 0) : %d\n", (a < b) || (b > 0)); // Logical OR
    printf("!(a == b)          : %d\n\n", !(a == b));        // Logical NOT

    // 3. INCREMENT AND DECREMENT OPERATORS
    int x = 10;
    printf("=== INCREMENT & DECREMENT OPERATORS (Initial x = %d) ===\n", x);
    printf("Post-increment (x++) : %d (prints 10, then x becomes 11)\n", x++);
    printf("Pre-increment  (++x) : %d (x becomes 12, then prints 12)\n", ++x);
    printf("Post-decrement (x--) : %d (prints 12, then x becomes 11)\n", x--);
    printf("Pre-decrement  (--x) : %d (x becomes 10, then prints 10)\n", --x);

    return 0;
}