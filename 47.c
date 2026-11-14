// Program to Show the Working of Bitwise Operators


#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);

    printf("\n--- Bitwise Operations ---\n");
    printf("Bitwise AND (a & b)        = %d\n", a & b);
    printf("Bitwise OR (a | b)         = %d\n", a | b);
    printf("Bitwise XOR (a ^ b)        = %d\n", a ^ b);
    printf("Bitwise Complement (~a)    = %d\n", ~a);
    printf("Left Shift (a << 1)        = %d\n", a << 1);
    printf("Right Shift (a >> 1)       = %d\n", a >> 1);

    return 0;
}