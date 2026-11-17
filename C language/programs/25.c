// Check if string is palindrome.

#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int i, len, isPalin = 1;
    printf("Enter a string: ");
    scanf("%99s", str);
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalin = 0;
            break;
        }
    }
    if (isPalin)
        printf("\"%s\" is a Palindrome string.\n", str);
    else
        printf("\"%s\" is NOT a Palindrome string.\n", str);
    return 0;
}