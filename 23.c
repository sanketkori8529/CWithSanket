// Print multiplication table of N.

#include <stdio.h>
int main() {
    int n, i;
    printf("Enter a number N: ");
    scanf("%d", &n);
    printf("Multiplication Table of %d:\n", n);
    for (i = 1; i <= 10; i++) {
        printf("%d x %2d = %d\n", n, i, n * i);
    }
    return 0;
}