// Simple calculator (+, −, ×, ÷) using if-else.


#include <stdio.h>
int main() {
    char op;
    double n1, n2;
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter two operands: ");
    scanf("%lf %lf", &n1, &n2);
    if (op == '+') {
        printf("Result: %.2lf + %.2lf = %.2lf\n", n1, n2, n1 + n2);
    } else if (op == '-') {
        printf("Result: %.2lf - %.2lf = %.2lf\n", n1, n2, n1 - n2);
    } else if (op == '*') {
        printf("Result: %.2lf * %.2lf = %.2lf\n", n1, n2, n1 * n2);
    } else if (op == '/') {
        if (n2 != 0.0)
            printf("Result: %.2lf / %.2lf = %.2lf\n", n1, n2, n1 / n2);
        else
            printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Error: Invalid operator.\n");
    }
    return 0;
}