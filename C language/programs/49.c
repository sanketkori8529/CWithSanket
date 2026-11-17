// Program to find largest of two numbers using ternary operator

#include <stdio.h>

int main() {
    int num1, num2, largest;

    // Input two numbers from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Find the largest using the ternary operator
    largest = (num1 > num2) ? num1 : num2;

    // Display the result
    printf("Largest number is: %d\n", largest);

    return 0;
}