// Sum of digits using recursion
#include <stdio.h>

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}

int main()
{
    int n, result;

    printf("Enter n: ");
    scanf("%d", &n);

    result = sum(n);

    printf("Sum = %d", result);

    return 0;
}