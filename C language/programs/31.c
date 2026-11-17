//Print prime numbers from 1 to 50.


#include <stdio.h>
int main() {
    int num, i, isPrime;
    printf("Prime numbers between 1 and 50:\n");
    for (num = 2; num <= 50; num++) {
        isPrime = 1;
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}
     