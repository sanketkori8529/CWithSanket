// Write a C program to store 5 numbers in an array and print them in revers order.

#include <stdio.h>
int main() {
    int arr[5], i;
    printf("Enter 5 integers: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array elements in reverse order: ");
    for (i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}