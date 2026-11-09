//Fibonacci series (first 10 terms).

#include <stdio.h>
int main() {
    int n = 10, i;
    int t1 = 0, t2 = 1, nextTerm;
    printf("First %d terms of Fibonacci series:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
    return 0;
}