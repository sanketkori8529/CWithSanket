// Find GCD of two numbers.

#include <stdio.h>
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int x, y;
    printf("Enter two positive integers: ");
    scanf("%d %d", &x, &y);
    printf("GCD of %d and %d = %d\n", x, y, findGCD(x, y));
    return 0;
}