// Find GCD of two numbers using recurison.

#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int a, b, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    result = gcd(a, b);

    printf("GCD = %d", result);

    return 0;
}