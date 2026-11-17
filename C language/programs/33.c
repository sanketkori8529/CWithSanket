// Check palindrome number using function.

#include <stdio.h>
int isPalindrome(int n) {
    int original = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return (original == rev);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPalindrome(num))
        printf("%d is a Palindrome number.\n", num);
    else
        printf("%d is NOT a Palindrome number.\n", num);
    return 0;
}