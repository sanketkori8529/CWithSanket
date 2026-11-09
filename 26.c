// Sum of first N natural numbers using loop.


#include <stdio.h>
int main() {
    int n, i, sum = 0;
    printf("Enter a positive integer N: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    printf("Sum of first %d natural numbers = %d\n", n, sum);
    return 0;
}